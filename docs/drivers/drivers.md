
во всех открытых функциях драйверов кроме init первым аргументом должен быть struct dev_info* device

драйвера должны иметь функцию init

int init(struct dev_info*);





