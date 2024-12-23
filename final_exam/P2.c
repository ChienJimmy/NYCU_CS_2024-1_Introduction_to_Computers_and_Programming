#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORDER_ID_LEN 8
#define MAX_VILLAGE_NAME_LEN 15

typedef struct order_s {
	struct order_s *next;
	char order_id[ORDER_ID_LEN + 1];
	char consumer[MAX_VILLAGE_NAME_LEN + 1];
	enum {
		INGRED_A = 1,
		INGRED_B,
		INGRED_C,
	} ingredient_id;
	union {
		char ing_a[8];
		long ing_b;
		double ing_c;
	} amount;
} order_t;

typedef struct village_s {
	char name[MAX_VILLAGE_NAME_LEN + 1];
	unsigned long total_cost;
	order_t *order_list;
} village_t;

static const long unit_costs[] = {
	[INGRED_A] = 256,
	[INGRED_B] = 512,
	[INGRED_C] = 1024,
};

static village_t *init_village_array(int v_cnt);
static order_t *init_order_list(int o_cnt);
static void unify_orders(village_t *vills, int v_cnt, order_t *orders);
static void print_result(village_t *vills, int v_cnt);

int main()
{
	int village_cnt, order_cnt;
	scanf("%d%d", &village_cnt, &order_cnt);
	village_t *villages = init_village_array(village_cnt);
	if (!villages) {
		goto init_village_failed;
    }
	order_t *orders = init_order_list(order_cnt);
	if (!orders)  {
		goto init_order_failed;
    }
	unify_orders(villages, village_cnt, orders);
	print_result(villages, village_cnt);
	free(orders);

init_order_failed:
	free(villages);

init_village_failed:
	return 0;
}

static village_t *init_village_array(int v_cnt)
{
	village_t *villages = malloc(sizeof(village_t) * v_cnt);
	if (!villages) { // Ran out of memory
		return NULL;
    }
	for (int i = 0; i < v_cnt; i++) {
		scanf("%s", villages[i].name);
    }
	return villages;
}

static order_t *init_order_list(int o_cnt)
{
	order_t *orders = malloc(sizeof(order_t) * o_cnt);
	if (!orders) { // Ran out of memory
		return NULL;
    }
	for (int i = 0; i < o_cnt; i++) {
		// Read the content of order
		// the term %[^c] will use 'c' as delimiter while scanning the input
		scanf(" %[^:]:%u/%[^-]-%s",
				orders[i].order_id,
				&orders[i].ingredient_id,
				orders[i].amount.ing_a,
				orders[i].consumer);
		
		switch (orders[i].ingredient_id) {
			case INGRED_B:
				orders[i].amount.ing_b = atol(orders[i].amount.ing_a);
				break;
			case INGRED_C:
				orders[i].amount.ing_c = atof(orders[i].amount.ing_a);
				break;
			default:
				break;
		}
		// Construct orders into linked-list
		if (i) {
			orders[i - 1].next = orders + i;
        }
	}
	// End the linked-list
	orders[o_cnt - 1].next = NULL;
	return orders;
}

static void print_result(village_t *vills, int v_cnt)
{
	for (int i = 0; i < v_cnt; i++) {
		printf("%s %ld\n  ->", vills[i].name, vills[i].total_cost);
		for (order_t *optr = vills[i].order_list; optr; optr = optr->next) {
			printf(" %s", optr->order_id);
        }
		printf("\n");
	}
}

static int compare_orders(const void *a, const void *b)
{
    order_t *order_a = *(order_t **)a;
    order_t *order_b = *(order_t **)b;
    return strcmp(order_a->order_id, order_b->order_id);
}

static int compare_villages(const void *a, const void *b)
{
    village_t *village_a = (village_t *)a;
    village_t *village_b = (village_t *)b;
    return strcmp(village_a->name, village_b->name);
}


static void unify_orders(village_t *vills, int v_cnt, order_t *orders)
{
    order_t *order_array[1024];
    int order_count = 0;

    for (order_t *optr = orders; optr; optr = optr->next) {
        for (int i = 0; i < v_cnt; i++) {
            if (strcmp(optr->consumer, vills[i].name) == 0) {
                order_array[order_count++] = optr;
                switch (optr->ingredient_id) {
                    case INGRED_A:
                        vills[i].total_cost += unit_costs[INGRED_A] * atol(optr->amount.ing_a);
                        break;
                    case INGRED_B:
                        vills[i].total_cost += unit_costs[INGRED_B] * optr->amount.ing_b;
                        break;
                    case INGRED_C:
                        vills[i].total_cost += unit_costs[INGRED_C] * optr->amount.ing_c;
                        break;
                }
                break;
            }
        }
    }

    qsort(order_array, order_count, sizeof(order_t *), compare_orders);

    for (int i = 0; i < v_cnt; i++) {
        vills[i].order_list = NULL;
    }

    for (int i = 0; i < order_count; i++) {
        for (int j = 0; j < v_cnt; j++) {
            if (strcmp(order_array[i]->consumer, vills[j].name) == 0) {
                order_array[i]->next = vills[j].order_list;
                vills[j].order_list = order_array[i];
                break;
            }
        }
    }
    for (int i = 0; i < v_cnt; i++) {
        order_t *prev = NULL, *current = vills[i].order_list, *next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        vills[i].order_list = prev;
    }

    qsort(vills, v_cnt, sizeof(village_t), compare_villages);
}
