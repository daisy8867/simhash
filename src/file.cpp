#include "file.h"

uint64_t file2string(string infileName) {
	ifstream inFile(infileName.c_str());
	stringstream buffer;
	buffer << inFile.rdbuf();
    Simhash::Simhash<> hasher;
    uint64_t a = hasher.hash_tokenizer(buffer.str().c_str(), Simhash::Strspn());
	inFile.close();
//	cout << a << endl;
	return a;
}


int main(int argc, char** argv) {
	string dir (argv[1]);
    uint64_t limit(200);

    if (argc == 3) {
        limit = static_cast<uint64_t>(atol(argv[2]));
	}
	vector<string> files;
	vector<string> content;
//	string cmd = "find " + dir + " -type f > filelist";
//	system(cmd.c_str());
	ifstream inFile("filelist");
	stringstream buffer;
	buffer << inFile.rdbuf();
	string str;
	inFile.close();
    std::vector<Simhash::hash_t> masks;

    /* This is a vector of bitmasks describing a valid permutation. This
     * particular permutation has 6 blocks, where each of the blocks is kept in
     * the order that you'd expect. Changing the order of these items has the
     * effect of reordering the blocks. */
    masks.push_back(0xFFE0000000000000);
    masks.push_back(0x1FFC0000000000  );
    masks.push_back(0x3FF80000000     );
    masks.push_back(0x7FF00000        );
    masks.push_back(0xFFE00           );
    masks.push_back(0x1FF             );

    /* Create a table where we're interested in matches with 3 or fewer bytes
     * differing between two near-duplicate documents. */
    Simhash::Table duplicates(5, masks);

    /* We're going to insert a bunch of hashes, and then run a bunch of queries
     * on some hashes that should be considered near duplicates and some that
     * should not */
    Simhash::hash_t query(0), first(0), errors(0);
	while(buffer) {
		buffer >> str;
		query = file2string(str);
//        first   = duplicates.find(query);
//		if(!first)	duplicates.insert(file2string(str));
	}
	cout << query << endl;

//	stringstream newBuffer;
//	ifstream QinFile("qfilelist");
//	newBuffer << QinFile.rdbuf();
//	QinFile.close();
//	string qstr;
//	while(newBuffer) {
//		newBuffer >> qstr;
//		query = file2string(qstr);
//        first   = duplicates.find(query);
//		if(!first)	duplicates.insert(file2string(str));
////        if (first) {
////            std::cout << "Found " << first << " when looking for " << query << "(" << Simhash::num_differing_bits(first, query) << ")" << std::endl;
////        }
////        errors += !first ? 0 : 1;
//  }

//    std::cout << "Queries complete with " << errors << " errors" << std::endl;
//
//    size_t count(0);
//    Simhash::Table::const_iterator it( duplicates.begin());
//    Simhash::Table::const_iterator end(duplicates.end());
//    for(; it != end; ++it, ++count) {}
//
//    std::cout << "There are " << count << " items in the table" << std::endl;

	return 0;
}
