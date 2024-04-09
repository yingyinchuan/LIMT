#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <algorithm>
#include "HuffmanTree.hpp"

using std::string;
using std::vector;

struct ByteInfo
{
    char _ch;
    size_t _appearCount;
    string _chCode;
    ByteInfo(size_t appearCount = 0)
        : _appearCount(appearCount)
    {
    }

    ByteInfo operator+(const ByteInfo& other) const
    {
        return _appearCount + other._appearCount;
    }

    bool operator>(const ByteInfo& other) const
    {
        return _appearCount > other._appearCount;
    }

    bool operator!=(const ByteInfo& other) const
    {
        return _appearCount != other._appearCount;
    }

    bool operator==(const ByteInfo& other) const
    {
        return _appearCount == other._appearCount;
    }
};

class FileCompressHM
{
public:
    void CompressHM(const string& filePath);
    void UnCompressHM(const string& filePath);
    FileCompressHM();
    ~FileCompressHM();

private:
    void GenerateHuffmanCode(HuffmanTreeNode<ByteInfo>* root);
    void WriteHeadInfo(const string& filePath, FILE* out);
    string GetFilePostFix(const string& filePath);
    vector<ByteInfo> _fileInfo;
};

FileCompressHM::FileCompressHM()
{
    _fileInfo.resize(256);
    for (int i = 0; i < 256; i++)
    {
        _fileInfo[i]._ch = i;
    }
}

FileCompressHM::~FileCompressHM()
{
}

void FileCompressHM::CompressHM(const string& filePath)
{
    FILE* in = fopen(filePath.c_str(), "r");
    if (in == nullptr)
        return;

    char buffer[1024];
    while (true)
    {
        size_t size = fread(buffer, 1, 1024, in);
        if (size == 0)
            break;
        for (int i = 0; i < size; i++)
        {
            _fileInfo[buffer[i]]._appearCount++;
        }
    }
    ByteInfo invalid;
    HuffmanTree<ByteInfo> ht(_fileInfo, invalid);

    GenerateHuffmanCode(ht.GetRoot());

    FILE* out = fopen("test.myzip", "w");
    WriteHeadInfo(filePath, out);

    fseek(in, 0, SEEK_SET);
    char bits = 0;
    int bitcount = 0;

    while (true)
    {
        size_t size = fread(buffer, 1, 1024, in);
        if (0 == size)
            break;

        for (int i = 0; i < size; i++)
        {
            char ch = buffer[i];
            string& strCode = _fileInfo[ch]._chCode;
            for (int j = 0; j < strCode.size(); j++)
            {
                bits <<= 1;
                if (strCode[j] == '1')
                    bits |= 1;
                bitcount++;
                if (bitcount == 8)
                {
                    fputc(bits, out);
                    bits = 0;
                    bitcount = 0;
                }
            }
        }
    }

    if (bitcount != 0)
    {
        bits <<= (8 - bitcount);
        fputc(bits, out);
    }

    fclose(in);
    fclose(out);
}

void FileCompressHM::UnCompressHM(const string& filePath)
{
}

void FileCompressHM::GenerateHuffmanCode(HuffmanTreeNode<ByteInfo>* root)
{
    if (root == nullptr)
        return;
    GenerateHuffmanCode(root->_left);
    GenerateHuffmanCode(root->_right);

    if (root->_left == nullptr && root->_right == nullptr)
    {
        string& chCode = _fileInfo[root->_weight._ch]._chCode;
        HuffmanTreeNode<ByteInfo>* cur = root;
        HuffmanTreeNode<ByteInfo>* parent = cur->_parent;

        while (parent)
        {
            if (cur == parent->_left)
                chCode += "0";
            else if (cur == parent->_right)
                chCode += "1";

            cur = parent;
            parent = cur->_parent;
        }
        std::reverse(chCode.begin(), chCode.end());
    }
}

void FileCompressHM::WriteHeadInfo(const string& filePath, FILE* out)
{
    string HeadInfo;
    HeadInfo += GetFilePostFix(filePath);
    HeadInfo += '\n';

    string chInfo;
    int chCount = 0;
    for (auto& e : _fileInfo)
    {
        if (e._appearCount == 0)
            continue;

        chInfo += e._ch;
        chInfo += ':';
        chInfo += std::to_string(e._appearCount);
        chInfo += '\n';

        chCount++;
    }
    HeadInfo += std::to_string(chCount);
    HeadInfo += '\n';

    fwrite(HeadInfo.c_str(), 1, HeadInfo.size(), out);
    fwrite(chInfo.c_str(), 1, chInfo.size(), out);
}

string FileCompressHM::GetFilePostFix(const string& filePath)
{
    return filePath.substr(filePath.find_last_of('.') + 1);
}