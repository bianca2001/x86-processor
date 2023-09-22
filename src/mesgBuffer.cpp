struct mesg_buffer_char {
    long mesg_type;
    char mesg_text[100];
};

struct mesg_buffer_matrix {
    long mesg_type;
    char** mesg_text;
};

struct mesg_buffer_int {
    long mesg_type;
    int mesg_text;
};