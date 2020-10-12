#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include<library.h>
#define PROJECT_NAME    "LMS"



void testPassword(void);

int main() {

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
  CU_add_test(suite, "Password", testPassword);


  CU_basic_set_mode(CU_BRM_VERBOSE);


  CU_basic_run_tests();


  CU_cleanup_registry();

  return 0;
}

void testPassword(void) {
  CU_ASSERT(1 == Password("pass"));
  CU_ASSERT(1 == Password("wrong"));//dummy fail case


}
