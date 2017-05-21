#include "config.h"
#include <sys/acl.h>
#include <sys/types.h>
#include <acl/libacl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	char *file_path;
	char *aclText=NULL;
	acl_t acl=NULL;
	acl_entry_t entry=NULL;
	acl_permset_t permset;
	uid_t qualifier=1;

	file_path = argv[1];
	
        /* Get ACL for file */
        acl=acl_get_file_nofollow(file_path, ACL_TYPE_ACCESS);
        if ( acl == (acl_t)NULL ) {
                fprintf(stderr, "Failed to get ACL from file `%s': %s\n", file_path, strerror(errno));
                goto fail;
        }

        /* Grab string of original state of ACL */
        aclText=acl_to_any_text(acl, NULL, ',', TEXT_ABBREVIATE);
        if ( aclText == NULL ) {
                fprintf(stderr, "Failed to convert ACL to text: %s\n", strerror(errno));
                goto fail;
        }
	printf("%s\n", aclText);

	return 0;

	fail:
		return 1;

}
