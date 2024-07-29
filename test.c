#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "listechainee.h"
#include <stdbool.h>
#include "statistiques.h"
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

void test_create_node(void) {
    const char *test_word = "TEST";
    Node *mock_node = create_node(test_word);

    CU_ASSERT_STRING_EQUAL(test_word, mock_node->word);
    CU_ASSERT_PTR_EQUAL(mock_node->next, NULL);
}

void test_insert_in_order(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    CU_ASSERT(mock_list.word_count == 0);
    const char *word1 = "CHAT";
    const char *word2 = "MAISON";
    const char *word3 = "AVION";
    const char *word4 = "GLACE";
    const char *word5 = "LUNE";

    insert_in_order(&mock_list, word1);
    insert_in_order(&mock_list, word2);
    insert_in_order(&mock_list, word3);
    insert_in_order(&mock_list, word4);
    insert_in_order(&mock_list, word5);
    
    CU_ASSERT(mock_list.word_count == 5);

    CU_ASSERT_STRING_EQUAL(word3, mock_list.head->word);
    CU_ASSERT_STRING_EQUAL(word2, mock_list.tail->word);
    CU_ASSERT_STRING_EQUAL(word4, mock_list.head->next->next->word);
    CU_ASSERT_STRING_EQUAL(word1, mock_list.head->next->word);
    CU_ASSERT_STRING_EQUAL(word5, mock_list.head->next->next->next->word);
    free_word_list(&mock_list);
}

void test_free_list(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    CU_ASSERT(mock_list.word_count == 0);
    const char *word1 = "CHAT";
    const char *word2 = "MAISON";
    const char *word3 = "AVION";

    insert_in_order(&mock_list, word1);
    insert_in_order(&mock_list, word2);
    insert_in_order(&mock_list, word3);

    CU_ASSERT_EQUAL(3, mock_list.word_count);
    free_word_list(&mock_list);
    CU_ASSERT_EQUAL(0, mock_list.word_count);
    CU_ASSERT_PTR_EQUAL(mock_list.head, NULL);
}



void test_delete_duplicate(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    const char *word1 = "CHAT";
    const char *word2 = "MAISON";
    const char *word3 = "AVION";
    const char *word4 = "GLACE";
    const char *word5 = "LUNE";
    const char *word6 = "LUNE";
    const char *word7 = "AVION";

    insert_in_order(&mock_list, word1);
    insert_in_order(&mock_list, word2);
    insert_in_order(&mock_list, word3);
    insert_in_order(&mock_list, word4);
    insert_in_order(&mock_list, word5);
    insert_in_order(&mock_list, word6);
    insert_in_order(&mock_list, word7);

    // Comparer AVION à AVION
    CU_ASSERT_STRING_EQUAL(mock_list.head->word, mock_list.head->next->word);
    CU_ASSERT(mock_list.word_count == 7);

    delete_duplicate(&mock_list);
    
    CU_ASSERT(mock_list.word_count == 5);
    CU_ASSERT_STRING_EQUAL(word1, mock_list.head->next->word);

    free_word_list(&mock_list);


}

void test_distinct_letter_count(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    CU_ASSERT(mock_list.word_count == 0);
    const char *word1 = "AVION";
    const char *word2 = "CHAT";
    const char *word3 = "GLACE";
    const char *word4 = "LUNE";
    const char *word5 = "MAISON";

    insert_in_order(&mock_list, word1);
    insert_in_order(&mock_list, word2);
    insert_in_order(&mock_list, word3);
    insert_in_order(&mock_list, word4);
    insert_in_order(&mock_list, word5);

    CU_ASSERT_EQUAL(14, distinct_letter_count(&mock_list));


}

void test_find_most_repeated_letter(void) {
    LinkedList mock_list;
    initialize_list(&mock_list);

    CU_ASSERT(mock_list.word_count == 0);
    const char *word1 = "AVION";
    const char *word2 = "CHAT";
    const char *word3 = "GLACE";
    const char *word4 = "LUNE";
    const char *word5 = "MAISON";

    insert_in_order(&mock_list, word1);
    insert_in_order(&mock_list, word2);
    insert_in_order(&mock_list, word3);
    insert_in_order(&mock_list, word4);
    insert_in_order(&mock_list, word5);

    CU_ASSERT_EQUAL('A', find_most_repeated_letter(&mock_list));


}



int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("LinkedList Suite", 0, 0);
    CU_add_test(suite, "test of initialize_list", test_initialize_list);
    CU_add_test(suite, "test of insert_into_empty_list", test_insert_into_empty_list);
    CU_add_test(suite, "test of create_node", test_create_node);
    CU_add_test(suite, "test of insert_in_order", test_insert_in_order);
    CU_add_test(suite, "test of delete_duplicate", test_delete_duplicate);
    CU_add_test(suite, "test of free_word_list", test_free_list);
    
    CU_pSuite suite_stats = CU_add_suite("Statistics Suite", 0, 0);
    CU_add_test(suite_stats, "test of distinct_letter_count", test_distinct_letter_count);
    CU_add_test(suite_stats, "test of find most repeated letter", test_find_most_repeated_letter);


    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    CU_cleanup_registry();
    return 0;
}
