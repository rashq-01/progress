#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CACHE_SIZE 10
// Define structure for cache node
typedef struct CacheNode {
char *key;
char *value;
struct CacheNode *next;
} CacheNode;
// Define structure for cache
typedef struct {
CacheNode *hash[CACHE_SIZE];
} Cache;
// Function to create a new cache node
CacheNode *createCacheNode(char *key, char *value) {
CacheNode *node = malloc(sizeof(CacheNode));
if (!node) {
fprintf(stderr, "Memory allocation failed\n");
exit(1);
}
node->key = strdup(key);
node->value = strdup(value);
node->next = NULL;
return node;
}
// Function to calculate hash value
int hash(char *key) {
int hash_val = 0;
while (*key) {
hash_val += *key++;
}
return hash_val % CACHE_SIZE;
}
// Function to insert a key-value pair into the cache
void put(Cache *cache, char *key, char *value) {
int index = hash(key);
CacheNode *node = createCacheNode(key, value);
node->next = cache->hash[index];
cache->hash[index] = node;
}
// Function to get the value associated with a key from the cache
char *get(Cache *cache, char *key) {
int index = hash(key);
CacheNode *node = cache->hash[index];
while (node != NULL) {
if (strcmp(node->key, key) == 0) {
return node->value;
}
node = node->next;
}
return NULL; // Key not found
}
// Main function
int main() {
Cache cache;
for (int i = 0; i < CACHE_SIZE; i++) {
cache.hash[i] = NULL;
}
char key[50], value[50];
int choice;
do {
printf("\n1. Insert a key-value pair\n");
printf("2. Retrieve value for a key\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter key: ");
scanf("%s", key);
printf("Enter value: ");
scanf("%s", value);
put(&cache, key, value);
printf("Key-value pair inserted into cache.\n");
break;
case 2:
printf("Enter key to retrieve value: ");
scanf("%s", key);
char *result = get(&cache, key);
if (result)
printf("Value for key '%s': %s\n", key, result);
else
printf("Key '%s' not found\n", key);
break;
case 3:
printf("Exiting...\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 3);
// Free allocated memory
for (int i = 0; i < CACHE_SIZE; i++) {
CacheNode *current = cache.hash[i];
while (current != NULL) {
CacheNode *temp = current;
current = current->next;
free(temp->key);
free(temp->value);
free(temp);
}
}
return 0;
}