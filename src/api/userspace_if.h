// Интерфейс API функций для userspace

#ifndef INCL_API_USIF
#define INCL_API_USIF

void sys_print_text(struct registers_struct* args, struct registers_struct* result);

void sys_new_line(struct registers_struct* args, struct registers_struct* result);

void sys_cursor_update(struct registers_struct* args, struct registers_struct* result);

void sys_clear_display(struct registers_struct* args, struct registers_struct* result);

void sys_get_current_symbol(struct registers_struct* args, struct registers_struct* result);

void sys_delete_current_symbol(struct registers_struct* args, struct registers_struct* result);

void sys_read_sector(struct registers_struct* args, struct registers_struct* result);

void sys_write_sector(struct registers_struct* args, struct registers_struct* result);

void sys_execute_program(struct registers_struct* args, struct registers_struct* result);

void sys_get_execute_program(struct registers_struct* args, struct registers_struct* result);

void sys_get_keyboard_buffer(struct registers_struct* args, struct registers_struct* result);

void sys_get_keyboard_buffer_ptr(struct registers_struct* args, struct registers_struct* result);

void sys_get_keyboard_shift_pressed(struct registers_struct* args, struct registers_struct* result);

void sys_get_keyboard_ctrl_pressed(struct registers_struct* args, struct registers_struct* result);

void sys_get_keyboard_alt_pressed(struct registers_struct* args, struct registers_struct* result);

void sys_get_display_cursor_pos_x(struct registers_struct* args, struct registers_struct* result);

void sys_get_display_cursor_pos_y(struct registers_struct* args, struct registers_struct* result);

void sys_get_ticks(struct registers_struct* args, struct registers_struct* result);

void sys_get_device_count(struct registers_struct* args, struct registers_struct* result);

void sys_get_device_info(struct registers_struct* args, struct registers_struct* result);

void sys_set_display_cursor_pos_x(struct registers_struct* args, struct registers_struct* result);

void sys_set_display_cursor_pos_y(struct registers_struct* args, struct registers_struct* result);

#endif
