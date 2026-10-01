#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
  item_list[index].price = price;

  item_list[index].sku = malloc(strlen(sku) + 1);
  strcpy(item_list[index].sku, sku);

  item_list[index].category = malloc(strlen(category) + 1);
  strcpy(item_list[index].category, category);

  item_list[index].name = malloc(strlen(name) + 1);
  strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    free(item_list[i].sku);
    free(item_list[i].category);
    free(item_list[i].name);
  }
  free(item_list);
}

double average_price(Item *item_list, int size)
{
  double sum = 0;
  int i;
  for (i = 0; i < size; i++)
  {
    sum = sum + item_list[i].price;
  }
  return sum / size;
}

void print_items(Item *item_list, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("###############\n");
    printf("item name = %s\n", item_list[i].name);
    printf("item sku = %s\n", item_list[i].sku);
    printf("item category = %s\n", item_list[i].category);
    printf("item price = %f\n", item_list[i].price);
  }
}

int main(int argc, char *argv[])
{
  int size = 5;
  Item *item_list = malloc(size * sizeof(Item));

  add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
  add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
  add_item(item_list, 2.50, "14512", "bakery", "bread", 2);
  add_item(item_list, 4.25, "33021", "produce", "strawberries", 3);
  add_item(item_list, 7.80, "55093", "Indian_Snacks", "Samosa", 4);

  print_items(item_list, size);
  printf("###############\n");
  printf("average price of items = %f\n", average_price(item_list, size));

  if (argc > 1)
  {
    int ct = 0;
    while (ct < size && strcmp(item_list[ct].sku, argv[1]) != 0)
    {
      ct++;
    }

    if (ct < size)
    {
      printf("\nFound item:\n");
      printf("item name = %s\n", item_list[ct].name);
      printf("item sku = %s\n", item_list[ct].sku);
      printf("item category = %s\n", item_list[ct].category);
      printf("item price = %f\n", item_list[ct].price);
    }
    else
    {
      printf("\nitem not found\n");
    }
  }

  free_items(item_list, size);
  return 0;
}
