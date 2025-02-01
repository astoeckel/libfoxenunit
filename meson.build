#  libfoxenunit -- Minimal unit test library for C
#  Copyright (C) 2018  Andreas Stöckel
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Affero General Public License as
#  published by the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Affero General Public License for more details.
#
#  You should have received a copy of the GNU Affero General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.

project('libfoxenunit', 'c', default_options : ['c_std=c89'])

# This is a header only library
inc_foxen = include_directories('src')

# Compile the example program
exe_example = executable(
    'example',
    'examples/example.c',
    include_directories: inc_foxen,
    install: false)

# Compile and register the unit tests
exe_test_success = executable(
    'test_success',
    'test/test_success.c',
    include_directories: inc_foxen,
    install: false)
exe_test_fail = executable(
    'test_fail',
    'test/test_fail.c',
    include_directories: inc_foxen,
    install: false)
test('test_success', exe_test_success)
test('test_fail', exe_test_fail)

# Install the header file
install_headers(
    ['src/foxen-unittest.h'],
)

# Generate a Pkg config file
pkg = import('pkgconfig')
pkg.generate(
    subdirs: [],
    name: 'libfoxenunit',
    version: '1.0',
    filebase: 'libfoxenunit',
    description: 'Minimal unittest library')


# Export the dependency
dep_foxenunit = declare_dependency(include_directories: inc_foxen)
