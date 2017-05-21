#include "config.h"
#include <sys/acl.h>
#include <sys/types.h>
#include <acl/libacl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	char *filePath;
	char *aclText;
	int rc, entryIdx;
	acl_t acl=NULL;
	acl_entry_t entry=NULL;
	acl_permset_t permset;
	uid_t qualifier=1;

	filePath = argv[1];
	aclText = argv[2];
	
	acl = acl_from_text(argv[2]);
	rc = acl_check(acl, &entryIdx);
	if (rc < 0) {
		fprintf(stderr, "%s - %s\n", aclText, strerror(errno));
			goto fail;
	} else if (rc > 0) {
		fprintf(stderr, "access ACL '%s': %s at entry %d\n", aclText, acl_error(rc), entryIdx);
		goto fail;
	}

	rc=acl_set_file_nofollow(filePath, ACL_TYPE_ACCESS, acl);
	if (rc != 0) {
		fprintf(stderr, "Failed to set acl on file `%s': %s\n", filePath, strerror(rc == -1 ? errno: rc));
		goto fail;
	}

	return 0;	

	fail:
		return 1;

}
