acl_t __acl_get_file(const char *, acl_type_t ,
	             ssize_t (*)(const char *, const char *,
				   void *, size_t),
	             int (*)(const char*, struct stat*));
