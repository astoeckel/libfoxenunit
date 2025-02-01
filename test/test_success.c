/*
 *  libfoxenunit -- Minimalist unit test library for C
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

#include <foxen-unittest.h>

static void test_ok_expect() {
	EXPECT_EQ(0, 0);
	EXPECT_EQ(0, 1 - 1);
	EXPECT_EQ(1 - 1, 0);
	EXPECT_EQ(0.0, 0.0);
	EXPECT_EQ(0.1, 0.1);
	EXPECT_EQ(0.0f, 0.0f);
	EXPECT_EQ(0.01f, 0.01f);
	EXPECT_EQ('a', 'a');

	EXPECT_GT(1, 0);
	EXPECT_GT(1.0, 0.0);
	EXPECT_GT(1.0f, 0.0f);
	EXPECT_GT('b', 'a');

	EXPECT_GE(1, 0);
	EXPECT_GE(0.01, 0.0);
	EXPECT_GE(0.01f, 0.0f);
	EXPECT_GE('b', 'a');
	EXPECT_GE(1, 1);
	EXPECT_GE(0.01, 0.01);
	EXPECT_GE(0.01f, 0.01f);
	EXPECT_GE('b', 'b');

	EXPECT_LT(0, 1);
	EXPECT_LT(0.0, 1.0);
	EXPECT_LT(0.0f, 1.0f);
	EXPECT_LT('a', 'b');

	EXPECT_LE(0, 1);
	EXPECT_LE(0.0, 0.01);
	EXPECT_LE(0.0f, 0.01f);
	EXPECT_LE('a', 'b');
	EXPECT_LE(1, 1);
	EXPECT_LE(0.01, 0.01);
	EXPECT_LE(0.01f, 0.01f);
	EXPECT_LE('b', 'b');

	EXPECT_NE(1, 0);
	EXPECT_NE(0.01, 0.0);
	EXPECT_NE(0.01f, 0.0f);
	EXPECT_NE('b', 'a');
	EXPECT_NE(0, 1);
	EXPECT_NE(0.0, 0.01);
	EXPECT_NE(0.0f, 0.01f);
	EXPECT_NE('a', 'b');

	EXPECT_TRUE(1);
	EXPECT_TRUE('a');
	EXPECT_TRUE(1.0);
	EXPECT_TRUE(0.1);
	EXPECT_TRUE(0.1f);

	EXPECT_FALSE(0);
	EXPECT_FALSE(NULL);

	EXPECT_NEAR(1.0, 1.0, 1e-6);
	EXPECT_NEAR(1.0, 1.0 + 1e-7, 1e-6);
}

static void test_ok_assert() {
	ASSERT_EQ(0, 0);
	ASSERT_EQ(0, 1 - 1);
	ASSERT_EQ(1 - 1, 0);
	ASSERT_EQ(0.0, 0.0);
	ASSERT_EQ(0.1, 0.1);
	ASSERT_EQ(0.0f, 0.0f);
	ASSERT_EQ(0.01f, 0.01f);
	ASSERT_EQ('a', 'a');

	ASSERT_GT(1, 0);
	ASSERT_GT(1.0, 0.0);
	ASSERT_GT(1.0f, 0.0f);
	ASSERT_GT('b', 'a');

	ASSERT_GE(1, 0);
	ASSERT_GE(0.01, 0.0);
	ASSERT_GE(0.01f, 0.0f);
	ASSERT_GE('b', 'a');
	ASSERT_GE(1, 1);
	ASSERT_GE(0.01, 0.01);
	ASSERT_GE(0.01f, 0.01f);
	ASSERT_GE('b', 'b');

	ASSERT_LT(0, 1);
	ASSERT_LT(0.0, 1.0);
	ASSERT_LT(0.0f, 1.0f);
	ASSERT_LT('a', 'b');

	ASSERT_LE(0, 1);
	ASSERT_LE(0.0, 0.01);
	ASSERT_LE(0.0f, 0.01f);
	ASSERT_LE('a', 'b');
	ASSERT_LE(1, 1);
	ASSERT_LE(0.01, 0.01);
	ASSERT_LE(0.01f, 0.01f);
	ASSERT_LE('b', 'b');

	ASSERT_NE(1, 0);
	ASSERT_NE(0.01, 0.0);
	ASSERT_NE(0.01f, 0.0f);
	ASSERT_NE('b', 'a');
	ASSERT_NE(0, 1);
	ASSERT_NE(0.0, 0.01);
	ASSERT_NE(0.0f, 0.01f);
	ASSERT_NE('a', 'b');

	ASSERT_TRUE(1);
	ASSERT_TRUE('a');
	ASSERT_TRUE(1.0);
	ASSERT_TRUE(0.1);
	ASSERT_TRUE(0.1f);

	ASSERT_FALSE(0);
	ASSERT_FALSE(NULL);

	ASSERT_NEAR(1.0, 1.0, 1e-6);
	ASSERT_NEAR(1.0, 1.0 + 1e-7, 1e-6);
}

static int main_wrapper() {
	RUN(test_ok_expect);
	RUN(test_ok_assert);
	DONE;
}

int main() {
	return main_wrapper();
}
