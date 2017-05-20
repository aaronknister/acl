acl_t __acl_get_file(const char *, acl_type_t ,
	             ssize_t (*)(const char *, const char *,
				   void *, size_t),
	             ssize_t (*)(const char*, struct stat*));
