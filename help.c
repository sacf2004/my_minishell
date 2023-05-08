if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            my_printf("%s: Command not found.\n", args[2]);