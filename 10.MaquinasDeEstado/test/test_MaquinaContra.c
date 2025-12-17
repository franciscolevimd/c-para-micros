#include "unity.h"
#include "MaquinaContra.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_MaquinaDeEstados_De_IDEAL_a_DIGITO_1(void) {
  uint8_t Estado = MaquinaDeEstados(IDEAL, 0);
  TEST_ASSERT_EQUAL(DIGITO_1, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_1_a_DIGITO_2(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_1, 1);
  TEST_ASSERT_EQUAL(DIGITO_2, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_1_a_ERROR(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_1, 8);
  TEST_ASSERT_EQUAL(ERROR, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_2_a_DIGITO_3(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_2, 0);
  TEST_ASSERT_EQUAL(DIGITO_3, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_2_a_ERROR(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_2, 7);
  TEST_ASSERT_EQUAL(ERROR, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_3_a_VALIDO(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_3, 5);
  TEST_ASSERT_EQUAL(VALIDO, Estado);
}

void test_MaquinaDeEstados_De_DIGITO_3_a_ERROR(void) {
  uint8_t Estado = MaquinaDeEstados(DIGITO_3, 7);
  TEST_ASSERT_EQUAL(ERROR, Estado);
}

void test_MaquinaDeEstados_De_VALIDO_a_IDEAL(void) {
  uint8_t Estado = MaquinaDeEstados(VALIDO, 0);
  TEST_ASSERT_EQUAL(IDEAL, Estado);
}

void test_MaquinaDeEstados_De_ERROR_a_DIGITO_1(void) {
  uint8_t Estado = MaquinaDeEstados(ERROR, 0);
  TEST_ASSERT_EQUAL(DIGITO_1, Estado);
}

