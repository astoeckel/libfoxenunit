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

#include <foxen/unittest.h>

void test_ok() {
	EXPECT_EQ(0, 0);
	EXPECT_GT(1, 0);
	EXPECT_GE(1, 0);
	EXPECT_GE(1, 1);
	EXPECT_LT(0, 1);
	EXPECT_LE(0, 1);
	EXPECT_LE(1, 1);
	EXPECT_NE(0, 1);
	EXPECT_TRUE(1);
	EXPECT_FALSE(0);
	EXPECT_NEAR(1.0, 1.0, 1e-6);
	EXPECT_NEAR(1.0, 1.0 + 1e-7, 1e-6);
}

void test_fail() {
	EXPECT_EQ(0, 1);
	EXPECT_GT(0, 1);
	EXPECT_GT(1, 1);
	EXPECT_GE(0, 1);
	EXPECT_LT(1, 0);
	EXPECT_LT(1, 1);
	EXPECT_LE(1, 0);
	EXPECT_NE(0, 0);
	EXPECT_TRUE(0);
	EXPECT_FALSE(1);
	EXPECT_NEAR(1.0, 1.1, 1e-6);
}

void test_assert() {
	ASSERT_TRUE(0);
	printf("Assert will longjmp back to main(). This will not be printed.");
}

int main() {
	RUN(test_ok);
	RUN(test_fail);
	RUN(test_assert); /* Assertions MUST be executed from RUN */
	DONE;
}
