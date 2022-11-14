#
#pragma region <imports>
#pragma region "export header imports"

#pragma endregion
#
#pragma region "platform-dependent imports"

#pragma endregion
#
#pragma region "platform-independent imports"
#include <iostream>
#pragma endregion
#
#pragma region "3rd-party imports"
#include "../include/carbonplus.h"
#pragma endregion
#
#pragma region "shared imports"

#pragma endregion
#
#pragma region "local imports"

#pragma endregion         
#pragma endregion
#
#
int _cdecl main(int argc, char** argv) {
	/*
	std::experimental::filesystem::path pt;
	carbon::sys::path pm;

	pm = "C:\\Windows\\System32\\svchost.exe";
	pt = "C:\\Windows\\System32\\svchost.exe";

	std::cout << "Mine:   " << pm << std::endl;
	std::cout << "Theirs: " << pt.root_directory() << std::endl;
	*/

	/*
	carbon::sys::path path;

	path.append("C:\\Playground\\.build\\download.file.zip");
	std::cout << "Path: " << path << std::endl;

	path.setparent("C:\\Windows\\System32");
	std::cout << "Path: " << path << std::endl;

	path.setfname("svchost");
	std::cout << "Path: " << path << std::endl;

	path.setextension("exe");
	std::cout << "Path: " << path << std::endl;
	*/

	/*
	carbon::sys::path path1;
	carbon::sys::path path2;

	path1 = "C:\\Windows\\System32\\svchost.exe";
	path2 = "C:\\Windows\\";

	printf("Path1: [%s]\n", path1.c_str());
	printf("Path2: [%s]\n", path2.c_str());

	if (path1.isdescendantof(path2))
		printf("[%s] IS descendant of [%s]\n", path1.c_str(), path2.c_str());
	else {
		printf("[%s] is NOT descendant of [%s]\n", path1.c_str(), path2.c_str());
	}
	
	printf("\n");

	printf("Path: [%s]\n", path1.c_str());
	printf("Path of Supposed Parent: [%s]\n", path2.c_str());

	if (path2.isancestorof(path1))
		printf("[%s] IS ancestor of [%s]\n", path2.c_str(), path1.c_str());
	else {
		printf("[%s] is NOT ancestor of [%s]\n", path2.c_str(), path1.c_str());
	}
	*/

	/*
	carbon::sys::path path1;
	carbon::sys::path path2;

	path1 = "C:\\Windows\\System32\\svchost.exe";
	path2 = "C:\\Windows\\System32////";

	if (path2.isparentof(path1))
		printf("Is parent!\n");
	else {
		printf("Is NOT parent!\n");
	}
	*/

	/*
	carbon::sys::path path;

	path = "C:\\Windows\\System32\\svchost.exe";

	printf("Names:\n");
	path.enum_names([&](carbon::sys::path& s_file_name) {
		printf(" > %s\n", s_file_name.c_str());

		return true;
	});

	printf("Subpaths:\n");
	path.enum_subpaths([&](carbon::sys::path& s_file_path) {
		printf(" > %s\n", s_file_path.c_str());

		return true;
	});
	*/

	/*
	carbon::sys::path path;
	carbon::type::string str;

	str = "C:";
	path.append(str);
	std::cout << "Path: " << path << std::endl;

	str = "Windows\\/";
	path.append(str);
	std::cout << "Path: " << path << std::endl;
	*/

	/*
	carbon::sys::path dp = "C:\\playground";
	carbon::sys::enum_directory_contents(dp, [&](carbon::sys::path& s_directory_path, carbon::sys::path& s_file_name) {
		carbon::sys::path s_file_path;

		s_file_path.append(s_directory_path);
		s_file_path.append(s_file_name);

		printf(">> %s\n", s_file_path.c_str());

		return true;
	});
	*/
	
	/*
	auto it = carbon::sys::directory_contents_iterator("C:\\playground");

	while (it.has_next()) {
		printf(" > %s\n", it.next().c_str());
	}
	*/

	/*
	carbon::sys::path path1 = "C:\\Windows\\/System32\\\\\\svchost.exe";
	carbon::sys::path path2 = "C:\\Shit\\..\\.\\Windows\\/System32\\\\\\svchost.EXE";

	std::cout << "Path1: " << path1 << std::endl;
	std::cout << "Path2: " << path2 << std::endl;

//	path1.resolve();
//	path2.resolve();

	std::cout << "Path1: " << path1 << std::endl;
	std::cout << "Path2: " << path2 << std::endl;

	std::cout << "Equals: " << (path1.equals(path2) ? "Yes" : "No") << std::endl;
	*/

	/*
	carbon::sys::path path = "C:\\Windows\\/System32\\\\\\svchost.exe/";

	std::cout << "Path: " << path << std::endl;

	printf("Subpaths:\n");
	auto it = path.subpaths_iterator();

	while (it.has_next()) {
		printf("\t* %s\n", it.next().c_str());
	}

	printf("Names:\n");
	auto itx = path.names_iterator();

	while (itx.has_next()) {
		printf("\t* %s\n", itx.next().c_str());
	}
	*/

	/*
	carbon::sys::path path = "C:\\//Windows\\\\System32\\Drivers/////VideoChipDrv.sys";

	std::cout << "Path: " << path << std::endl;

	std::cout << "Names:" << std::endl;
	for (auto& name : path.names()) {
		std::cout << "\t > " << name << std::endl;
	}

	std::cout << "Subpaths:" << std::endl;
	for (auto& name : path.subpaths()) {
		std::cout << "\t > " << name << std::endl;
	}
	*/

	/*
	carbon::sys::path path = "C:\\Windows\\System32\\Drivers\\VideoChipDrv.sys";

	std::cout << "Path: " << path << std::endl;

	path.setfname("test.exe");

	std::cout << "Path: " << path << std::endl;

	path.setparent("C:\\Playground");

	std::cout << "Path: " << path << std::endl;

	path.setdrive('D');

	std::cout << "Path: " << path << std::endl;
	*/

	/*
	carbon::sys::path path = "C:\\//\\/Windows/System32\\\\/Drivers/\\/\\/VideoChipDrv.sys";

	std::cout << "Raw Path: " << path << std::endl;

	path.normalize();

	std::cout << "Normalized Path: " << path << std::endl;
	*/

	/*
 	unsigned int       regsize;
	unsigned long long bigsize;

//	auto path = "C:\\proot\\safe\\.build\\UMBRELLAFX\\backend\\hello.txt";
	auto path = "C:\\proot\\safe\\.build\\UMBRELLAFX\\backend\\KaliBox.7z";

	regsize = carbon::sys::get_file_size(path);
	bigsize = carbon::sys::get_file_size_big(path);

	std::cout << "Reg Size: " << carbon::type::to_string(regsize) << std::endl;
	std::cout << "Big Size: " << carbon::type::to_string(bigsize) << std::endl;
	*/

	/*
	carbon::sys::path p1 = "Windows\\//System32/ola\\..\\\\..\\playground"; 
	carbon::sys::path p2 = "C:\\Windows\\//System32/ola\\..\\\\..\\playground";
	carbon::sys::path p3 = "C:";

	std::cout << "Path1: " << p1 << std::endl;
	std::cout << "Path2: " << p2 << std::endl;
	std::cout << "Path3: " << p3 << std::endl;

	p1.rmvdrive();
	p2.rmvdrive();
	p3.rmvdrive();

	std::cout << "Removed drives!" << std::endl;

	std::cout << "Path1: " << p1 << std::endl;
	std::cout << "Path2: " << p2 << std::endl;
	std::cout << "Path3: " << p3 << std::endl;
	*/

	/*
	carbon::sys::path p1a;
	carbon::sys::path p1r = "Windows\\//System32/ola\\..\\\\..\\playground"; // BUG!

	p1a = carbon::sys::current_process::resolve_path_abs(p1r);

	std::cout << "Resolving: " << p1r << std::endl;
	std::cout << "To: " << p1a << std::endl;
	*/

	/*
	carbon::sys::path ctx = "C:\\Windows\\System32\\Drivers";
	carbon::sys::path rel = "..\\..\\SysWow64\\svchost.exe";
	carbon::sys::path abs = rel.resolve(ctx);

	std::cout << "Resolving: " << rel << std::endl;
	std::cout << "From: " << ctx << std::endl;
	std::cout << "To: " << abs << std::endl;
	*/
}