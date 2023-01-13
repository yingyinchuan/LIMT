#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#pragma once

#include<stdio.h>
#include<assert.h>
#include<string.h>

typedef struct person
{
	char name[20];
	int age;
	char phone[12];
}person;

typedef struct contact
{
	person data[100];
	int sz;
}contact;

void mune();

int init(contact* p);

int exit(contact* p);

int add(contact* p);

int del(contact* p);

int search(contact* p);

int show(contact* p);

int mod(contact* p);

int sort(contact* p);

int findname(contact* p, char* name);

int trim(contact* p, int ret);
