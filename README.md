# libfoxenunit ― Minimal unit tests for C. With colours.

[![Build Status](https://travis-ci.org/astoeckel/libfoxenunit.svg?branch=master)](https://travis-ci.org/astoeckel/libfoxenunit)

Minimal unit test framework written in the C++ compatible subset of ANSI C89. Consists of a single header file `unittest.h`.

## Features

* Relatively lightweight at 160 lines of code
* Variety of `ASSERT` and `EXPECT` statements akin to those found in Google Test
* No heap allocations
* Uses ANSI escape codes on Unix platforms for colourful output! 🌈

Please be aware that this library does explicitly *not* support automatic test discovery. You have to manually list your unit tests in `main()`. See below for an example.

## Installation

### The simple way
Just copy `src/foxen-unittest.h` to a place where your compiler can find it or adjust your include directories. Done.

### The less simple way
Use [Meson](https://mesonbuild.com/) to build this library. To this end, do the following.

If you have not already done so, install `meson`, e.g. by using `pip`
```sh
pip3 install --user meson
```

Then download this repository, build and install!
```sh
git clone https://github.com/astoeckel/libfoxenunit libfoxenunit
cd libfoxenunit; mkdir build; cd build
meson .. # Use -Dprefix= to set the install prefix
ninja
ninja install
```

This will install a `pkgconfig` file, so you can use the library from other projects.

### The `meson`-specifc way

Copy the file `contrib/libfoxenunit.wrap` into the `subprojects` folder at the root of your `meson` project. Include `libfoxenunit` as a dependency in your `meson.build` as follows:
```meson
dep_foxenunit = dependency(
    'libfoxenunit',
    fallback:['libfoxenunit', 'dep_foxenunit'])
```

## Usage

Usage is as follows:

```C
#include <foxen-unittest.h>

/* Unit tests are just plain functions */
static void test() {
	EXPECT_EQ(1, 1); /* This will be OK */
}

int main() {
	RUN(test); /* List all your unit tests here */
	DONE;
}

```

See `examples/example.c` for a more comprehensive example.

## Available ASSERT and EXPECT macros

* `EXPECT_EQ(should, is)`, `ASSERT_EQ(should, is)`<br/>Checks for equality, i.e. `should == is`
* `EXPECT_GT(should, is)`, `ASSERT_GT(should, is)`<br/>Checks for `should` being greater than `is`, i.e. `should > is`
* `EXPECT_GE(should, is)`, `ASSERT_GE(should, is)`<br/>Checks for `should` being greater than or equal to `is`, i.e. `should >= is`
* `EXPECT_LT(should, is)`, `ASSERT_LT(should, is)`<br/>Checks for `should` being smaller than `is`, i.e. `should < is`
* `EXPECT_LE(should, is)`, `ASSERT_LE(should, is)`<br/>Checks for `should` being smaller than or equal to `is`, i.e. `should <= is`
* `EXPECT_NE(should, is)`, `ASSERT_NE(should, is)`<br/>Checks for `should` being not equal to `is`, i.e. `should != is`
* `EXPECT_TRUE(is)`, `ASSERT_TRUE(is)`<br/>Checks for `is` evaluating to the boolean expression `true`
* `EXPECT_FALSE(is)`, `ASSERT_FALSE(is)`<br/>Checks for `is` evaluating to the boolean expression `false`
* `EXPECT_NEAR(should, is, err)`, `ASSERT_NEAR(should, is, err)`<br/>Ensures that the difference between `should` and `is` is smaller or equal to `err`.

`EXPECT` macros are used to print an error message and mark a test as failed if the given condition is not fulfilled.

`ASSERT` macros do the same, but will also stop executing this particular test. Usually `ASSERT` is only used if failing this condition would make it impossible to continue with the test.

## FAQ regarding the *Foxen* series of C libraries

**Q: What's with the name?**

**A:** [*Foxen*](http://kingkiller.wikia.com/wiki/Foxen) is a mysterious glowing object guiding Auri through the catacumbal “Underthing”. The *Foxen* software libraries are similar in key aspects: mysterious and catacumbal. Probably less useful than an eternal sympathy lamp though.

**Q: What is the purpose and goal of these libraries?**

**A:** The *Foxen* libraries are extremely small C libraries that rely on the [Meson](https://mesonbuild.com/) build system for dependency management. One common element is that the libraries do not use [heap memory allocations](https://github.com/astoeckel/libfoxenmem). They can thus be easily compiled to tiny, standalone [WASM](https://webassembly.org/) code.

**Q: Why?**

**A:** Excellent question! The author mainly created these libraries because he grew tired of copying his own source code files between projects all the time.

**Q: Would you recommend to use these libraries in my project?**

**A:** That depends. Some of the code is fairly specialized according to my own needs and might not be intended to be general. If what you are going to use these libraries for aligns with their original purpose, then sure, go ahead. Otherwise, I'd probably advise against using these libraries, and as explained below, I'm not super open to expanding their scope.

**Q: Can you licence these libraries under a something more permissive than AGPLv3?**

**A:** Maybe, if you ask nicely. I'm not a fan of giving my work away “for free” (i.e., allowing inclusion of my code in commercial or otherwise proprietary software) without getting something back (in particular public access to the source code of the things other people built with it). That being said, some of the `foxen` libraries may be too trivial to warrant the use of a strong copyleft licence. Correspondingly, I might reconsider this decision for individual libraries. See “[Why you shouldn't use the Lesser GPL for your next library](https://www.gnu.org/licenses/why-not-lgpl.en.html)” for more info.

**Q: Can I contribute?**

**A:** Sure! Feel free to open an issue or a PR. However, be warned that since I've mainly developed these libraries for use in my own stuff, I might be a little picky about what I'm going to include and what not.

## Licence

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.
