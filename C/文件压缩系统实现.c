#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义哈夫曼树节点
typedef struct Node {
    char data;
    int frequency;
    struct Node *left, *right;
} Node;

// 哈夫曼编码结构
typedef struct HuffmanCode {
    char data;
    char *code;
} HuffmanCode;

// 函数声明
Node *buildHuffmanTree(FILE *inputFile);
void generateHuffmanCodes(Node *root, char *code, int depth, HuffmanCode *codes, int *codeIndex);
void compressFile(FILE *inputFile, FILE *outputFile, HuffmanCode *codes);
void decompressFile(FILE *inputFile, FILE *outputFile, Node *root);
void freeHuffmanTree(Node *root);

int main() {
    // 步骤1：初始化，建立哈夫曼树并保存编码映射到文件
    FILE *sourceFile = fopen("sourcefile.txt", "r");
    FILE *huffmanTreeFile = fopen("huffman_tree.txt", "w");

    Node *huffmanTree = buildHuffmanTree(sourceFile);

    // 生成哈夫曼编码
    HuffmanCode codes[256];
    int codeIndex = 0;
    generateHuffmanCodes(huffmanTree, "", 0, codes, &codeIndex);

    // 将哈夫曼编码写入文件
    for (int i = 0; i < 256; i++) {
        if (codes[i].code != NULL) {
            fprintf(huffmanTreeFile, "%c %s\n", codes[i].data, codes[i].code);
        }
    }

    fclose(sourceFile);
    fclose(huffmanTreeFile);

    // 步骤2：压缩文件
    sourceFile = fopen("sourcefile.txt", "r");
    FILE *compressedFile = fopen("compressed", "wb");

    compressFile(sourceFile, compressedFile, codes);

    fclose(sourceFile);
    fclose(compressedFile);

    // 步骤3：解压文件
    FILE *inputCompressedFile = fopen("compressed", "rb");
    FILE *uncompressedFile = fopen("uncompressed.txt", "w");

    decompressFile(inputCompressedFile, uncompressedFile, huffmanTree);

    fclose(inputCompressedFile);
    fclose(uncompressedFile);

    // 释放哈夫曼树的内存
    freeHuffmanTree(huffmanTree);

    return 0;
}

// 构建哈夫曼树
Node *buildHuffmanTree(FILE *inputFile) {
    // 统计字符频率
    int frequency[256] = {0};
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        frequency[ch]++;
    }

    // 构建哈夫曼树
    // 为每个字符创建一个叶子节点，并将其插入最小堆（优先队列）
    // 重复合并两个最小频率的节点，直到只剩下一个根节点
    // 返回根节点
    // （省略详细实现）

    return NULL;
}

// 生成哈夫曼编码
void generateHuffmanCodes(Node *root, char *code, int depth, HuffmanCode *codes, int *codeIndex) {
    if (root == NULL) {
        return;
    }

    // 如果是叶子节点，存储编码
    if (!root->left && !root->right) {
        codes[*codeIndex].data = root->data;
        codes[*codeIndex].code = strdup(code);
        (*codeIndex)++;
    }

    // 递归处理左右子树
    code[depth] = '0';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->left, code, depth + 1, codes, codeIndex);

    code[depth] = '1';
    code[depth + 1] = '\0';
    generateHuffmanCodes(root->right, code, depth + 1, codes, codeIndex);
}

// 压缩文件
void compressFile(FILE *inputFile, FILE *outputFile, HuffmanCode *codes) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // 根据字符找到对应的哈夫曼编码，写入文件
        fprintf(outputFile, "%s", codes[ch].code);
    }
}

// 解压文件
void decompressFile(FILE *inputFile, FILE *outputFile, Node *root) {
    Node *current = root;
    int bit;
    while ((bit = fgetc(inputFile)) != EOF) {
        // 根据读取的01序列进行解码
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        // 如果到达叶子节点，写入文件并重置current
        if (current->left == NULL && current->right == NULL) {
            fprintf(outputFile, "%c", current->data);
            current = root;
        }
    }
}

// 释放哈夫曼树内存
void freeHuffmanTree(Node *root) {
    if (root == NULL) {
        return;
    }

    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}
