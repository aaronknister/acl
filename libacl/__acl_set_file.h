int __acl_set_file(const char *path_p, acl_type_t type, acl_t acl,
   	           ssize_t (*setxattr_fun)(const char *, const char *,
				   void *, size_t))
