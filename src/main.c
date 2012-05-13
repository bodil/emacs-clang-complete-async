#include <clang-c/Index.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "completion.h"
#include "msg_callback.h"


/* This function is intended to help debugging transmition issues, and should 
   not be called in the final release version. */
void __dump_session(const completion_Session *session, FILE *fp)
{
    int i_arg = 0;
    for ( ; i_arg < session->num_args; i_arg++) {
        fprintf(fp, "[%-2d]: %s\n", i_arg, session->cmdline_args[i_arg]);
    }

    fprintf(fp, "filename: %s\n"
                "code:\n%s\n", 
        session->src_filename, session->src_buffer); fflush(fp);
}


int main(int argc, char *argv[])
{
    completion_Session session;
    startup_completionSession(argc, argv, &session);
    __dump_session(&session, stdout);

    for ( ; ; )
    {
        completion_AcceptRequest(&session, stdin);
        /* __dump_session(&session, stdout); */
    }

    return 0;
}