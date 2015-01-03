/****************************************
 * description: hash table
 * author: nibz@qq.com
 * *************************************/

#include "hash.h"

#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	struct hash_s hash;
	struct item_s item;

	memset(&hash, 0, sizeof hash);

	srand(getpid());

	int n[HASH_TABLE_LENGTH] = {0};
	int i = 0;
	int j = rand() % HASH_TABLE_LENGTH;

	strcpy(item.value, "abcdefghij");

	printf("push hash table\n");
	while (1)
	{
		item.key = rand();
		strfry(item.value);

		n[i++] = item.key;
		printf("(%d, 0x%08x, %s)\n", i-1, item.key, item.value);
		push(&hash, item);

		if (i == j) break;
	}

	printf("print hash table\n");
	for (i = 0; i < HASH_TABLE_LENGTH; i++)
	{
		if (hash.item[i].key == 0) continue;
		printf("(%d, 0x%08x, %s)\n", i, hash.item[i].key, hash.item[i].value);
	}

	printf("find `value' from hash table\n");
	i = rand() % j;
	item.key = n[i];
	memset(item.value, 0, sizeof item.value);

	int ret = find(&hash, &item);

	printf("(%d, %d, 0x%08x, %s)\n", ret, i, item.key, item.value);
	printf("(%d/%d)\n", hash.used, HASH_TABLE_LENGTH);

#ifdef DEBUG
	printf("sleep 60 seconds, just ctrl-c\n");
	sleep(60);
#endif

	return 0;
}
