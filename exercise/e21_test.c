#include <CUnit/CUnit.h>
#include "CUnit/Basic.h"
#include "e21.c"

void test_permtest_length_1(void){
  unsigned int perm[1] = {1};
  int res = permtest(perm,1);

  if (res==1) {
    CU_PASS(perm: 1);
  }
  else {
    CU_FAIL(perm: 1 erwartet: 1);
  }

  unsigned int perm2[1] = {0};
  res = permtest(perm2,1);
  if (res==0) {
    CU_PASS(perm: 0);
  }
  else {
    CU_FAIL(perm: 0 erwartet: 0);
  }

  unsigned int perm3[1] = {2};
  res = permtest(perm3,1);
  if (res==0) {
    CU_PASS(perm: 2);
  }
  else {
    CU_FAIL(perm: 2 erwartet: 0);
  }

}

void test_permtest_length_9(void){
  unsigned int perm[9] = {1,3,6,8,2,9,4,7,5};
  int res = permtest(perm,9);

  if (res==1) {
    CU_PASS(perm: 1 3 6 8 2 9 4 7 5);
  }
  else {
    CU_FAIL(perm: 1 3 6 8 2 9 4 7 5 erwartet: 1);
  }

  unsigned int perm2[9] = {1,3,0,8,2,9,4,7,5};
  res = permtest(perm2,9);
  if (res==0) {
    CU_PASS(perm: 1 3 0 8 2 9 4 7 5);
  }
  else {
    CU_FAIL(perm: 1 3 0 8 2 9 4 7 5 erwartet: 0);
  }

  unsigned int perm3[9] = {1,3,6,8,2,9,10,7,5};
  res = permtest(perm3,9);
  if (res==0) {
    CU_PASS(perm: 1 3 6 8 2 9 10 7 5);
  }
  else {
    CU_FAIL(perm: 1 3 6 8 2 9 10 7 5 erwartet: 0);
  }

  unsigned int perm4[9] = {2,3,4,5,6,7,8,9,10};
  res = permtest(perm4,9);
  if (res==0) {
    CU_PASS(perm: 2 3 4 5 6 7 8 9 10);
  }
  else {
    CU_FAIL(perm: 2 3 4 5 6 7 8 9 10 erwartet: 0);
  }

  unsigned int perm5[9] = {1,3,6,8,2,9,4,7,6};
  res = permtest(perm5,9);
  if (res==0) {
    CU_PASS(perm: 1 3 6 8 2 9 4 7 6);
  }
  else {
    CU_FAIL(perm: 1 3 6 8 2 9 4 7 6 erwartet: 0);
  }

}

void test_permtest_length_12(void){
  unsigned int perm[12] = {1,3,6,8,2,10,9,11,12,4,7,5};
  int res = permtest(perm,12);

  if (res==1) {
    CU_PASS(perm: 1 3 6 8 2 10 9 11 12 4 7 5);
  }
  else {
    CU_FAIL(perm: 1 3 6 8 2 10 9 11 12 4 7 5 erwartet: 1);
  }

  unsigned int perm2[12] = {11,1,3,0,8,2,9,4,7,5,10,6};
  res = permtest(perm2,12);
  if (res==0) {
    CU_PASS(perm: 11 1 3 0 8 2 9 4 7 5 10 6);
  }
  else {
    CU_FAIL(perm: 11 1 3 0 8 2 9 4 7 5 10 6 erwartet: 0);
  }

  unsigned int perm3[12] = {1,3,13,6,8,2,9,10,7,5,11,4};
  res = permtest(perm3,12);
  if (res==0) {
    CU_PASS(perm: 1 3 13 6 8 2 9 10 7 5 11 4);
  }
  else {
    CU_FAIL(perm: 1 3 13 6 8 2 9 10 7 5 11 4 erwartet: 0);
  }

  unsigned int perm4[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
  res = permtest(perm4,12);
  if (res==0) {
    CU_PASS(perm: 2 3 4 5 6 7 8 9 10 11 12 13);
  }
  else {
    CU_FAIL(perm: 2 3 4 5 6 7 8 9 10 11 12 13 erwartet: 0);
  }

  unsigned int perm5[12] = {1,3,6,8,2,9,4,7,6,10,5,12};
  res = permtest(perm5,12);
  if (res==0) {
    CU_PASS(perm: 1 3 6 8 2 9 4 7 6 10 5 12);
  }
  else {
    CU_FAIL(perm: 1 3 6 8 2 9 4 7 6 10 5 12 erwartet: 0);
  }

}


int init_suite1(void)
{
  return 0;
}

int clean_suite1(void)
{
  return 0;
}


void cleanup(){}

main(){
 CU_pSuite pSuite = NULL;

/* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of permtest, length: 1", test_permtest_length_1)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of permtest, length: 9", test_permtest_length_9)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "test of permtest, length: 12", test_permtest_length_12)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
