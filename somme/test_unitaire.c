/*************** Tests unitaires du module math ****************/
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "math.h"
#include <stdio.h>
#include "erreur.h"
#include "nombre.h"

/** Montage de la fixation - appelé avant chaque cas de test. **/
int init_suite(void) { return 0; }

/* Démontage de la fixation - appelé après chaque cas de test. */
int clean_suite(void) { return 0; }

void Test_des_cas_de_base(void){
	self.assertEqual(somme(1, 2), 3)
	self.assertEqual(somme(-1, 1), 0)
    self.assertEqual(somme(-1, -1), -2)
}
void Test_des_cas_avec_des_nombres_flottants(void){
	self.assertEqual(somme(2.5, 3.1), 5.6)
    self.assertEqual(somme(-1.1, 1.1), 0.0)
}
void Test_des_cas_avec_zero(void){
	self.assertEqual(somme(0, 0), 0)
    self.assertEqual(somme(0, 5), 5)
}

/******************* Lancement des tests ***********************/
int main ( void )
{
   CU_pSuite pSuite = NULL;
   unsigned int status = 0;

   /* initialisation des test CUnit */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* ajout de la suite de test */
   pSuite = CU_add_suite( "Test somme", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* ajout des cas de test dans la suite de test */
   if ( (NULL == CU_add_test(pSuite, "Cas de test - somme avec argument normal", Test_des_cas_de_base)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - somme avec arguments flottants", Test_des_cas_avec_des_nombres_flottants)) ||
        (NULL == CU_add_test(pSuite, "Cas de test - somme avec arguments zéro", Test_des_cas_avec_zero))
      )
   {;
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* lancement de tous les tests avac l'interface de base */
   CU_basic_set_mode(CU_BRM_NORMAL);
   if ( CUE_SUCCESS != CU_basic_run_tests() )
      return CU_get_error();
   
   status = CU_get_number_of_tests_failed();
   CU_basic_show_failures(CU_get_failure_list());
  
   /* cloture des tests */
   CU_cleanup_registry();
   return status;
}

