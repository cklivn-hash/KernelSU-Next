#include <linux/errno.h>

// Built instead of preinit.c when the target's UAPI headers are not installed
// (KSU_NO_PREINIT). The SUSFS fs/exec.c hooks still reference these symbols,
// so provide no-op versions that leave execve untouched.

struct filename;
struct user_arg_ptr;

int ksu_setup_preinit_file(struct filename **filename_ptr, struct user_arg_ptr *argv_user)
{
    return -EINVAL;
}

int ksu_preinit_handle_post_execveat(int *fd, struct filename **filename_ptr, void *argv_user, void *envp_user,
                                     int *flags, int *retval, int *preinit_fd)
{
    return 0;
}
