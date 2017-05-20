acl_t __acl_get_file(const char *path_p, acl_type_t type,
	             ssize_t (*getxattr_fun)(const char *, const char *,
				   void *, size_t),
	             ssize_t (*stat_fun)(const char *, struct stat *))
