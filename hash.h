/****************************************
 * description: hash table
 * author: nibz@qq.com
 * *************************************/

#ifndef _HASH_H
#define _HASH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VALUE_LENGTH      (0x10)
#define HASH_TABLE_LENGTH (10007) // 10007 is a primer number.

enum
{
	EXIT_NOT_FOUND = 2,
	EXIT_HASH_TABLE_FULL = 3,
};

struct item_s
{
	int  key;
	char value[VALUE_LENGTH];
};

struct hash_s
{
	struct item_s item[HASH_TABLE_LENGTH];
	int    used; // It stands for used position.
};

int push(struct hash_s *hash, struct item_s item)
{
	if (hash == NULL || item.key == 0)
		return EXIT_FAILURE;

	int l = item.key % HASH_TABLE_LENGTH;

	while (hash->item[l].key != 0)
	{
#ifdef DEBUG
		printf("hash collision, try next position\n");
#endif
		l = (++l) % HASH_TABLE_LENGTH;
		if (l == item.key % HASH_TABLE_LENGTH)
		{
			return EXIT_HASH_TABLE_FULL;
		}
	}

	hash->item[l].key = item.key;
	strcpy(hash->item[l].value, item.value);

	hash->used++;

	return EXIT_SUCCESS;
}

int find(struct hash_s *hash, struct item_s *item)
{
	if (hash == NULL || item->key == 0)
		return EXIT_FAILURE;

	int l = item->key % HASH_TABLE_LENGTH;

	while (item->key != hash->item[l].key)
	{
#ifdef DEBUG
		printf("hash collision, try next position\n");
#endif
		l = (++l) % HASH_TABLE_LENGTH;
		if (l == item->key % HASH_TABLE_LENGTH)
		{
			return EXIT_NOT_FOUND;
		}
	}

	strcpy(item->value, hash->item[l].value);

	return EXIT_SUCCESS;
}

#endif // _HASH_H
