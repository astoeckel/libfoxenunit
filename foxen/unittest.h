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

/**
 * @file unittest.h
 *
 * A minimal, though (most importantly) colourful unit testing framework for
 * plain C.
 *
 * @author Andreas Stöckel
 */

#ifndef FOXEN_UNITTEST_H
#define FOXEN_UNITTEST_H

#include <setjmp.h> /* Jikes. Required as an exception replacement in ASSERT. */
#include <stdio.h>

#ifdef __unix__
#include <unistd.h>
#endif

#ifdef __GNUC__
#define FX_VAR_NOT_USED __attribute__ ((unused))
#else
#define FX_VAR_NOT_USED
#endif

static volatile int fx_test_n_failed = 0;
static volatile int fx_test_n_success = 0;
static volatile int fx_test_failed = 0;
static volatile int fx_this_test_failed = 0;
static int fx_test_use_colour = -1;
static jmp_buf FX_VAR_NOT_USED fx_test_assert_buffer;

#undef FX_VAR_NOT_USED

/**
 * Prints an error message to stderr; strips the ANSI escape codes at runtime
 * if so desired. Colours are automatically disabled if stderr is not a TTY.
 *
 * @param s is the constant string that should be printed.
 */
static void fx_print(char const *s) {
	if (fx_test_use_colour == -1) {
#ifdef __unix__
		fx_test_use_colour = isatty(STDERR_FILENO);
#else
		fx_test_use_colour = 0;
#endif
	}
	if (fx_test_use_colour) {
		fputs(s, stderr);
	} else {
		char const *s0 = s;
		while (*s) {
			if (*s == '\33') {
				fprintf(stderr, "%*.*s", 0, (int)(s - s0), s0);
				do {
					++s;
				} while (*s && *s != 'm');
				if (!*s) {
					return;
				}
				s0 = ++s;
			} else {
				++s;
			}
		}
		fputs(s0, stderr);
	}
}

#define FX_ANSI_RED "\33[38;5;166;1m"
#define FX_ANSI_GRAY "\33[37;2m"
#define FX_ANSI_GREEN "\33[38;5;40;1m"
#define FX_ANSI_ORANGE "\33[38;5;220;1m"
#define FX_ANSI_RESET "\33[0m"

#define FX_ABS(X) ((X) >= 0 ? (X) : (-(X)))

#define FX_STR_DETAIL(X) #X
#define FX_STR(X) FX_STR_DETAIL(X)

#define FX_TO_BOOL(X) (((X) != 0) ? 1 : 0)

#define FX_PRINT_ERR(STR) fx_print(FX_ANSI_RED "[ERR]" FX_ANSI_RESET " " STR)
#define FX_PRINT_WARN(STR) \
	fx_print(FX_ANSI_ORANGE "[!!!]" FX_ANSI_RESET " " STR)
#define FX_PRINT_OK(STR) fx_print(FX_ANSI_GREEN "[OK!]" FX_ANSI_RESET " " STR)
#define FX_PRINT_ARROW(STR) fx_print(FX_ANSI_GRAY "---->" FX_ANSI_RESET " " STR)
#define FX_PRINT_INDENT(STR) fx_print("      " STR)

#define EXPECT(should, is, rel, msg)                       \
	do {                                                   \
		fx_this_test_failed = 0;                           \
		if (!((should)rel(is))) {                          \
			FX_PRINT_ERR("Assertion failed in " __FILE__   \
			             ", line " FX_STR(__LINE__) "\n"); \
			FX_PRINT_WARN("Expected «" msg "»\n");         \
			fx_test_failed = 1;                            \
			fx_this_test_failed = 1;                       \
		}                                                  \
	} while (0)

#define ASSERT(should, is, rel, msg)           \
	do {                                       \
		EXPECT(should, is, rel, msg);          \
		if (fx_this_test_failed) {             \
			longjmp(fx_test_assert_buffer, 1); \
		}                                      \
	} while (0)

#define RUN(test)                                           \
	do {                                                    \
		fx_test_failed = 0;                                 \
		FX_PRINT_ARROW("Running test \"" #test "\"\n");     \
		if (!setjmp(fx_test_assert_buffer)) {               \
			test();                                         \
		}                                                   \
		if (fx_test_failed) {                               \
			fx_test_n_failed++;                             \
			FX_PRINT_ERR("Test \"" #test "\" failed!\n");   \
		} else {                                            \
			fx_test_n_success++;                            \
			FX_PRINT_OK("Test \"" #test "\" successful\n"); \
		}                                                   \
	} while (0)

#define DONE                                                        \
	do {                                                            \
		fx_print(FX_ANSI_GRAY "=====" FX_ANSI_RESET "\n");          \
		if (fx_test_n_failed) {                                     \
			FX_PRINT_ERR("");                                       \
		} else {                                                    \
			FX_PRINT_OK("");                                        \
		}                                                           \
		fprintf(stderr, "Successful tests: %d; Failed tests: %d\n", \
		        fx_test_n_success, fx_test_n_failed);               \
		return fx_test_n_failed ? 1 : 0;                            \
	} while (0)

#define EXPECT_EQ(should, is) EXPECT(should, is, ==, #is " == " #should)
#define ASSERT_EQ(should, is) ASSERT(should, is, ==, #is " == " #should)
#define EXPECT_GT(should, is) EXPECT(should, is, >, #should " > " #is)
#define ASSERT_GT(should, is) ASSERT(should, is, >, #should " > " #is)
#define EXPECT_GE(should, is) EXPECT(should, is, >=, #should " >= " #is)
#define ASSERT_GE(should, is) ASSERT(should, is, >=, #should " >= " #is)
#define EXPECT_LT(should, is) EXPECT(should, is, <, #should " < " #is)
#define ASSERT_LT(should, is) ASSERT(should, is, <, #should " < " #is)
#define EXPECT_LE(should, is) EXPECT(should, is, <=, #should " <= " #is)
#define ASSERT_LE(should, is) ASSERT(should, is, <=, #should " <= " #is)
#define EXPECT_NE(should, is) EXPECT(should, is, !=, #is " != " #should)
#define ASSERT_NE(should, is) ASSERT(should, is, !=, #is " != " #should)
#define EXPECT_TRUE(is) EXPECT(1, FX_TO_BOOL(is), ==, "bool(" #is ") == TRUE")
#define ASSERT_TRUE(is) ASSERT(1, FX_TO_BOOL(is), ==, "bool(" #is ") == TRUE")
#define EXPECT_FALSE(is) EXPECT(0, FX_TO_BOOL(is), ==, "bool(" #is ") == FALSE")
#define ASSERT_FALSE(is) ASSERT(0, FX_TO_BOOL(is), ==, "bool(" #is ") == FALSE")
#define EXPECT_NEAR(should, is, err) \
	EXPECT(FX_ABS(should - is), err, <=, "|" #should " - " #is "| <= " #err)
#define ASSERT_NEAR(should, is, err) \
	ASSERT(FX_ABS(should - is), err, <=, "|" #should " - " #is "| <= " #err)

#endif /* FOXEN_UNITTEST_H */
