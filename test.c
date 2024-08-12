#include <CUnit/Basic.h>
#include "listechainee.h"
#include <stdbool.h>
#include "statistiques.h"
#include "helper.h"
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

    CU_ASSERT_EQUAL('\0', find_most_repeated_letter(&mock_list));


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

void test_is_empty_line(void) {
    const char *test_line = "               ";
    const char *test_line2 = "\n";
    const char *test_line3 = "AMERTUME";
    const char *test_line4 = "                   \n";
    const char *test_line5 = "                    O";

    CU_ASSERT(is_empty_line(test_line));
    CU_ASSERT(!is_empty_line(test_line5));
    CU_ASSERT(is_empty_line(test_line2));
    CU_ASSERT(is_empty_line(test_line4));
    CU_ASSERT(!is_empty_line(test_line3));
}

void test_insert_word_from_file(void) {
    const char *file_name = "test.txt";
    FILE *file = fopen(file_name, "r");
    CU_ASSERT_PTR_NOT_NULL(file);

    LinkedList mock_list;
    initialize_list(&mock_list);
    insert_word_from_file(file, &mock_list);

    CU_ASSERT(mock_list.word_count == 120);
    CU_ASSERT_STRING_EQUAL("AMERTUME", mock_list.head->word);
    CU_ASSERT_STRING_EQUAL("UNIVERS", mock_list.tail->word);
    CU_ASSERT_STRING_EQUAL("AMERTUME", mock_list.head->next->word);

    delete_duplicate(&mock_list);

    CU_ASSERT(mock_list.word_count == 5);
    free_word_list(&mock_list);
}

void test_count_lines(void) {
    const char *file_name = "test.txt";
    const char *file_name2 = "test_empty_line.txt";
    FILE *file = fopen(file_name, "r");
    FILE *file2 = fopen(file_name2, "r");
    CU_ASSERT_PTR_NOT_NULL(file);
    CU_ASSERT_PTR_NOT_NULL(file2);


    CU_ASSERT_EQUAL(24, count_lines(file));
    CU_ASSERT_EQUAL(24, count_lines(file2));
}

void test_validate_argc(void) {
    CU_ASSERT(validate_argc(4));
    CU_ASSERT(validate_argc(2));
    CU_ASSERT(!validate_argc(3));
    CU_ASSERT(!validate_argc(6));

}

void test_validate_argv(void) {
    int mock_argc = 4;
    char *mock_argv[] = {"./tri", "test.txt", "-S", "output.txt"};
    char *mock_argv2[] = {"./tri", "test.txt", "-s", "output.txt"};
 
    CU_ASSERT(validate_argv(mock_argc, mock_argv));
    CU_ASSERT(!validate_argv(mock_argc, mock_argv2));
}

int main(void) {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("LinkedList Suite", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(suite, "test of initialize_list", test_initialize_list) || 
        NULL == CU_add_test(suite, "test of insert_into_empty_list", test_insert_into_empty_list)||
        NULL == CU_add_test(suite, "test of create_node", test_create_node) ||
        NULL == CU_add_test(suite, "test of insert_in_order", test_insert_in_order) ||
        NULL == CU_add_test(suite, "test of delete_duplicate", test_delete_duplicate) ||
        NULL == CU_add_test(suite, "test of free_word_list", test_free_list) ||
        NULL == CU_add_test(suite, "test of insert_word_from_file", test_insert_word_from_file)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

   
    CU_pSuite suite_stats = CU_add_suite("Statistics Suite", NULL, NULL);
    if (NULL == suite_stats) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(suite_stats, "test of distinct_letter_count", 
        test_distinct_letter_count) || NULL == CU_add_test(suite_stats, 
        "test of find_most_repeated_letter", test_find_most_repeated_letter) ||
        NULL == CU_add_test(suite_stats, "test of is_empty_line", test_is_empty_line) ||
        NULL == CU_add_test(suite_stats, "test of count_lines", test_count_lines)) {

        CU_cleanup_registry();
        return CU_get_error();
        
    }


    CU_pSuite suite_helper = CU_add_suite("Statistics Suite", NULL, NULL);
    if (NULL == suite_helper) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if (NULL == CU_add_test(suite_helper, "test of validate_argc",
        test_validate_argc) || NULL == CU_add_test(suite_helper, 
        "test of validate_argv", test_validate_argv))  {

        CU_cleanup_registry();
        return CU_get_error();

    }


    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
    
}
