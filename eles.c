#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *current_file;
	const char *dir_name;

	if (argc > 2) {
		fprintf(stderr, "USAGE: eles [FILENAME]\n");
		return 1;
	} else if (argc == 2) {
		dir_name = argv[1];
	} else {
		dir_name = getcwd(NULL, 0);
	}

	dir = opendir(dir_name);
	if (!dir) {
		fprintf(stderr, "Error opening directory\n");
		return 1;
	}

	while ((current_file = readdir(dir)) != 0) {
		printf("%s\n", current_file->d_name);
	}

	return 0;
}
