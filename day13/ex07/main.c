#include "ft_btree.h"
#include <stdlib.h>
#include <stdio.h>

t_btree *btree_create_node(void *item);
void btree_apply_prefix(t_btree *root, void (applyf)(void ));
void btree_apply_infix(t_btree *root, void (applyf)(void ));
void btree_apply_suffix(t_btree *root, void (applyf)(void ));
void btree_insert_data(t_btree **root, void *item, int (cmpf)(void *, void *));
void *btree_search_item(t_btree *root, void *data_ref, int (cmpf)(void *, void *));

void	btree_apply_by_level(t_btree *root, 
void (*applyf)(void *item, int current_level, int is_first_elem));

int btree_level_count(t_btree *root);

void	print_item(void *item, int lvl, int is_first)
{
	printf("%s %d %d \n", item, lvl, is_first);
}
int main()
{
	// test traversals
	t_btree *test;
	test = btree_create_node("level0: root");
	test->left = btree_create_node("level1");
	test->right = btree_create_node("level1");
	test->left->left = btree_create_node("level2");
	test->left->right = btree_create_node("level2");
	test->right->right = btree_create_node("level2");
	test->right->left = btree_create_node("level2");
	
	test->right->right->right = btree_create_node("level3");
	printf("Max level: %d\n", btree_level_count(test));
	void (*print_ptr)(void *, int, int) = &print_item;
	btree_apply_by_level(test, print_ptr);
	//void *item = btree_search_item(root, "ppppppp", &ft_strcmp);
	//print_item(item);
	//btree_apply_infix(root, &print_item);
}