/*
 *  libfoxenunit -- Minimal unit test library for C
 *  Copyright (C) 2018  Andreas Stöckel
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stddef.h>

#include <foxen/unittest.h>

static int e = 0;

static void test_fail_expect_0() { EXPECT_NE(0, 0); }

static void test_fail_expect_1() { EXPECT_NE(0, 1 - 1); }

static void test_fail_expect_2() { EXPECT_NE(1 - 1, 0); }

static void test_fail_expect_3() { EXPECT_NE(0.0, 0.0); }

static void test_fail_expect_4() { EXPECT_NE(0.1, 0.1); }

static void test_fail_expect_5() { EXPECT_NE(0.0f, 0.0f); }

static void test_fail_expect_6() { EXPECT_NE(0.01f, 0.01f); }

static void test_fail_expect_7() { EXPECT_NE('a', 'a'); }

static void test_fail_expect_8() { EXPECT_LE(1, 0); }

static void test_fail_expect_9() { EXPECT_LE(1.0, 0.0); }

static void test_fail_expect_10() { EXPECT_LE(1.0f, 0.0f); }

static void test_fail_expect_11() { EXPECT_LE('b', 'a'); }

static void test_fail_expect_12() { EXPECT_LT(1, 0); }

static void test_fail_expect_13() { EXPECT_LT(0.01, 0.0); }

static void test_fail_expect_14() { EXPECT_LT(0.01f, 0.0f); }

static void test_fail_expect_15() { EXPECT_LT('b', 'a'); }

static void test_fail_expect_16() { EXPECT_LT(1, 1); }

static void test_fail_expect_17() { EXPECT_LT(0.01, 0.01); }

static void test_fail_expect_18() { EXPECT_LT(0.01f, 0.01f); }

static void test_fail_expect_19() { EXPECT_LT('b', 'b'); }

static void test_fail_expect_20() { EXPECT_GE(0, 1); }

static void test_fail_expect_21() { EXPECT_GE(0.0, 1.0); }

static void test_fail_expect_22() { EXPECT_GE(0.0f, 1.0f); }

static void test_fail_expect_23() { EXPECT_GE('a', 'b'); }

static void test_fail_expect_24() { EXPECT_GT(0, 1); }

static void test_fail_expect_25() { EXPECT_GT(0.0, 0.01); }

static void test_fail_expect_26() { EXPECT_GT(0.0f, 0.01f); }

static void test_fail_expect_27() { EXPECT_GT('a', 'b'); }

static void test_fail_expect_28() { EXPECT_GT(1, 1); }

static void test_fail_expect_29() { EXPECT_GT(0.01, 0.01); }

static void test_fail_expect_30() { EXPECT_GT(0.01f, 0.01f); }

static void test_fail_expect_31() { EXPECT_GT('b', 'b'); }

static void test_fail_expect_32() { EXPECT_EQ(1, 0); }

static void test_fail_expect_33() { EXPECT_EQ(0.01, 0.0); }

static void test_fail_expect_34() { EXPECT_EQ(0.01f, 0.0f); }

static void test_fail_expect_35() { EXPECT_EQ('b', 'a'); }

static void test_fail_expect_36() { EXPECT_EQ(0, 1); }

static void test_fail_expect_37() { EXPECT_EQ(0.0, 0.01); }

static void test_fail_expect_38() { EXPECT_EQ(0.0f, 0.01f); }

static void test_fail_expect_39() { EXPECT_EQ('a', 'b'); }

static void test_fail_expect_40() { EXPECT_FALSE(1); }

static void test_fail_expect_41() { EXPECT_FALSE('a'); }

static void test_fail_expect_42() { EXPECT_FALSE(1.0); }

static void test_fail_expect_43() { EXPECT_FALSE(0.1); }

static void test_fail_expect_44() { EXPECT_FALSE(0.1f); }

static void test_fail_expect_45() { EXPECT_TRUE(0); }

static void test_fail_expect_46() { EXPECT_TRUE(NULL); }

static void test_fail_expect_47() { EXPECT_NEAR(1.0, 1.1, 1e-6); }

static void test_fail_expect_48() { EXPECT_NEAR(1.0, 1.0 + 1e-5, 1e-6); }

static void test_fail_assert_0() {
	ASSERT_NE(0, 0);
	e = 1;
}

static void test_fail_assert_1() {
	ASSERT_NE(0, 1 - 1);
	e = 1;
}

static void test_fail_assert_2() {
	ASSERT_NE(1 - 1, 0);
	e = 1;
}

static void test_fail_assert_3() {
	ASSERT_NE(0.0, 0.0);
	e = 1;
}

static void test_fail_assert_4() {
	ASSERT_NE(0.1, 0.1);
	e = 1;
}

static void test_fail_assert_5() {
	ASSERT_NE(0.0f, 0.0f);
	e = 1;
}

static void test_fail_assert_6() {
	ASSERT_NE(0.01f, 0.01f);
	e = 1;
}

static void test_fail_assert_7() {
	ASSERT_NE('a', 'a');
	e = 1;
}

static void test_fail_assert_8() {
	ASSERT_LE(1, 0);
	e = 1;
}

static void test_fail_assert_9() {
	ASSERT_LE(1.0, 0.0);
	e = 1;
}

static void test_fail_assert_10() {
	ASSERT_LE(1.0f, 0.0f);
	e = 1;
}

static void test_fail_assert_11() {
	ASSERT_LE('b', 'a');
	e = 1;
}

static void test_fail_assert_12() {
	ASSERT_LT(1, 0);
	e = 1;
}

static void test_fail_assert_13() {
	ASSERT_LT(0.01, 0.0);
	e = 1;
}

static void test_fail_assert_14() {
	ASSERT_LT(0.01f, 0.0f);
	e = 1;
}

static void test_fail_assert_15() {
	ASSERT_LT('b', 'a');
	e = 1;
}

static void test_fail_assert_16() {
	ASSERT_LT(1, 1);
	e = 1;
}

static void test_fail_assert_17() {
	ASSERT_LT(0.01, 0.01);
	e = 1;
}

static void test_fail_assert_18() {
	ASSERT_LT(0.01f, 0.01f);
	e = 1;
}

static void test_fail_assert_19() {
	ASSERT_LT('b', 'b');
	e = 1;
}

static void test_fail_assert_20() {
	ASSERT_GE(0, 1);
	e = 1;
}

static void test_fail_assert_21() {
	ASSERT_GE(0.0, 1.0);
	e = 1;
}

static void test_fail_assert_22() {
	ASSERT_GE(0.0f, 1.0f);
	e = 1;
}

static void test_fail_assert_23() {
	ASSERT_GE('a', 'b');
	e = 1;
}

static void test_fail_assert_24() {
	ASSERT_GT(0, 1);
	e = 1;
}

static void test_fail_assert_25() {
	ASSERT_GT(0.0, 0.01);
	e = 1;
}

static void test_fail_assert_26() {
	ASSERT_GT(0.0f, 0.01f);
	e = 1;
}

static void test_fail_assert_27() {
	ASSERT_GT('a', 'b');
	e = 1;
}

static void test_fail_assert_28() {
	ASSERT_GT(1, 1);
	e = 1;
}

static void test_fail_assert_29() {
	ASSERT_GT(0.01, 0.01);
	e = 1;
}

static void test_fail_assert_30() {
	ASSERT_GT(0.01f, 0.01f);
	e = 1;
}

static void test_fail_assert_31() {
	ASSERT_GT('b', 'b');
	e = 1;
}

static void test_fail_assert_32() {
	ASSERT_EQ(1, 0);
	e = 1;
}

static void test_fail_assert_33() {
	ASSERT_EQ(0.01, 0.0);
	e = 1;
}

static void test_fail_assert_34() {
	ASSERT_EQ(0.01f, 0.0f);
	e = 1;
}

static void test_fail_assert_35() {
	ASSERT_EQ('b', 'a');
	e = 1;
}

static void test_fail_assert_36() {
	ASSERT_EQ(0, 1);
	e = 1;
}

static void test_fail_assert_37() {
	ASSERT_EQ(0.0, 0.01);
	e = 1;
}

static void test_fail_assert_38() {
	ASSERT_EQ(0.0f, 0.01f);
	e = 1;
}

static void test_fail_assert_39() {
	ASSERT_EQ('a', 'b');
	e = 1;
}

static void test_fail_assert_40() {
	ASSERT_FALSE(1);
	e = 1;
}

static void test_fail_assert_41() {
	ASSERT_FALSE('a');
	e = 1;
}

static void test_fail_assert_42() {
	ASSERT_FALSE(1.0);
	e = 1;
}

static void test_fail_assert_43() {
	ASSERT_FALSE(0.1);
	e = 1;
}

static void test_fail_assert_44() {
	ASSERT_FALSE(0.1f);
	e = 1;
}

static void test_fail_assert_45() {
	ASSERT_TRUE(0);
	e = 1;
}

static void test_fail_assert_46() {
	ASSERT_TRUE(NULL);
	e = 1;
}

static void test_fail_assert_47() {
	ASSERT_NEAR(1.0, 1.1, 1e-6);
	e = 1;
}

static void test_fail_assert_48() {
	ASSERT_NEAR(1.0, 1.0 + 1e-5, 1e-6);
	e = 1;
}

int main_wrapper() {
	RUN(test_fail_expect_0);
	RUN(test_fail_expect_1);
	RUN(test_fail_expect_2);
	RUN(test_fail_expect_3);
	RUN(test_fail_expect_4);
	RUN(test_fail_expect_5);
	RUN(test_fail_expect_6);
	RUN(test_fail_expect_7);
	RUN(test_fail_expect_8);
	RUN(test_fail_expect_9);
	RUN(test_fail_expect_10);
	RUN(test_fail_expect_11);
	RUN(test_fail_expect_12);
	RUN(test_fail_expect_13);
	RUN(test_fail_expect_14);
	RUN(test_fail_expect_15);
	RUN(test_fail_expect_16);
	RUN(test_fail_expect_17);
	RUN(test_fail_expect_18);
	RUN(test_fail_expect_19);
	RUN(test_fail_expect_20);
	RUN(test_fail_expect_21);
	RUN(test_fail_expect_22);
	RUN(test_fail_expect_23);
	RUN(test_fail_expect_24);
	RUN(test_fail_expect_25);
	RUN(test_fail_expect_26);
	RUN(test_fail_expect_27);
	RUN(test_fail_expect_28);
	RUN(test_fail_expect_29);
	RUN(test_fail_expect_30);
	RUN(test_fail_expect_31);
	RUN(test_fail_expect_32);
	RUN(test_fail_expect_33);
	RUN(test_fail_expect_34);
	RUN(test_fail_expect_35);
	RUN(test_fail_expect_36);
	RUN(test_fail_expect_37);
	RUN(test_fail_expect_38);
	RUN(test_fail_expect_39);
	RUN(test_fail_expect_40);
	RUN(test_fail_expect_41);
	RUN(test_fail_expect_42);
	RUN(test_fail_expect_43);
	RUN(test_fail_expect_44);
	RUN(test_fail_expect_45);
	RUN(test_fail_expect_46);
	RUN(test_fail_expect_47);
	RUN(test_fail_expect_48);
	RUN(test_fail_assert_0);
	RUN(test_fail_assert_1);
	RUN(test_fail_assert_2);
	RUN(test_fail_assert_3);
	RUN(test_fail_assert_4);
	RUN(test_fail_assert_5);
	RUN(test_fail_assert_6);
	RUN(test_fail_assert_7);
	RUN(test_fail_assert_8);
	RUN(test_fail_assert_9);
	RUN(test_fail_assert_10);
	RUN(test_fail_assert_11);
	RUN(test_fail_assert_12);
	RUN(test_fail_assert_13);
	RUN(test_fail_assert_14);
	RUN(test_fail_assert_15);
	RUN(test_fail_assert_16);
	RUN(test_fail_assert_17);
	RUN(test_fail_assert_18);
	RUN(test_fail_assert_19);
	RUN(test_fail_assert_20);
	RUN(test_fail_assert_21);
	RUN(test_fail_assert_22);
	RUN(test_fail_assert_23);
	RUN(test_fail_assert_24);
	RUN(test_fail_assert_25);
	RUN(test_fail_assert_26);
	RUN(test_fail_assert_27);
	RUN(test_fail_assert_28);
	RUN(test_fail_assert_29);
	RUN(test_fail_assert_30);
	RUN(test_fail_assert_31);
	RUN(test_fail_assert_32);
	RUN(test_fail_assert_33);
	RUN(test_fail_assert_34);
	RUN(test_fail_assert_35);
	RUN(test_fail_assert_36);
	RUN(test_fail_assert_37);
	RUN(test_fail_assert_38);
	RUN(test_fail_assert_39);
	RUN(test_fail_assert_40);
	RUN(test_fail_assert_41);
	RUN(test_fail_assert_42);
	RUN(test_fail_assert_43);
	RUN(test_fail_assert_44);
	RUN(test_fail_assert_45);
	RUN(test_fail_assert_46);
	RUN(test_fail_assert_47);
	RUN(test_fail_assert_48);
	DONE;
}

int main() {
	/* This unit test should succeed if the test fails */
	return ((main_wrapper() > 0) && (fx_test_n_failed == 98) &&
	        (fx_test_n_success == 0) && (e == 0))
	           ? 0
	           : 1;
}
