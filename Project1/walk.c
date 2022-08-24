#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ITEMS_PER_SALE 20

#define MAX_INVENTORY 10

#define MAX_SALES 20



struct Inventory

{

	int sku;

	int numInStock;

	double price;

};

struct SaleRecord
{

	int sku[MAX_ITEMS_PER_SALE];

	int numEachItemSold[MAX_ITEMS_PER_SALE];

	int numItemsInSale;
};



int main(void)

{

	struct Inventory inventory[MAX_INVENTORY] = {
	 {623, 71, 29.99} ,

		 {458, 20, 10.15}

	};

	struct SaleRecord sales[MAX_SALES] = {

	   { {458}, {3}, 1},

	   { {458, 623}, {1,2}, 2}

	};



	int numInventoryItems = 2, numSales = 2;

	int i, j, k, sku, numSold, found;

	double sum = 0.0;



	for (i = 0; i < numSales; i++)

	{

		for (j = 0; j < sales[i].numItemsInSale; j++)

		{

			sku = sales[i].sku[j];

			numSold = sales[i].numEachItemSold[j];

			found = 0;

			for (k = 0; k < numInventoryItems && !found; k++)

			{

				if (inventory[k].sku == sku)

				{

					sum += inventory[k].price * numSold;

					found = 1;

				}
			}

		}

	}

	printf("Total of goods sold = %.2lf\n", sum);

	return 0;

}																