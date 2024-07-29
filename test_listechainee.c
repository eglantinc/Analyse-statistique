#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "listechainee.h"
#include <stdlib.h>
#include <stdio.h>

void test_initialize_list(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    CU_ASSERT(mock_list.head == NULL);
    CU_ASSERT(mock_list.tail == NULL);
    CU_ASSERT(mock_list.word_count == 0);
}

void test_insert_into_empty_list(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);
    Node mock_node;

    CU_ASSERT(0 == mock_list.word_count);
    insert_into_empty_list(&mock_list, &mock_node);
    CU_ASSERT(1 == mock_list.word_count); 
    CU_ASSERT(&mock_node == mock_list.head);
    CU_ASSERT(&mock_node == mock_list.tail);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("LinkedList Suite", 0, 0);
    CU_add_test(suite, "test of initialize_list()", test_initialize_list);
    CU_add_test(suite, "test of insert_into_empty_list()", test_insert_into_empty_list);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return 0;
}
