struct mesg_buffer_char {
    long mesg_type;
    char* mesg_text;
};

struct mesg_buffer_char_matrix {
    long mesg_type;
    char* mesg_text[4];
};

struct mesg_buffer_int {
    long mesg_type;
    int mesg_text;
};

struct mesg_buffer_instruction{
    long mesg_type;
    int mesg_text[5];
};