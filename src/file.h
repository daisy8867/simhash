#ifndef READ_FILE_H_
#define READ_FILE_H_
//#define BOOST_NO_C++0x_SCOPED_ENUMS

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include "catch.hpp"

/* Include internals */
#include "cyclic.hpp"
#include "simhash.h"
/* And our tokenizer */
#include "tokenizers/strspn.h"
/* Include simhash */
#include "hash.hpp"

#include <string>
#include <stdint.h>
using namespace std;
//using namespace std::tr2::sys;


uint64_t file2string(string infileName);
#endif
