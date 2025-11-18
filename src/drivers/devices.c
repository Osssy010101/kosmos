#include "devices.h"
#include "../libs/device.h"
#include "pci/pci.h"

#include "drivers.h"


struct dev_info DEVICES_INFO[256];
unsigned int DEVICE_COUNT;


void device_log(struct dev_info* device) {
    unsigned int dev = 0;

    unsigned char x = _get_display_cursor_pos_x(dev);
    unsigned char y = _get_display_cursor_pos_y(dev);

    // Тип устройства
    if (device->is_pci_dev == 1) {
        _print_text("pci", 3, x, y, 7, 0, dev);
    } else if (device->is_leg_dev == 1) {
        _print_text("legacy", 6, x, y, 7, 0, dev);
        _new_line(dev);
        return;
    } else if (device->is_virt_dev == 1) {
        _print_text("virt", 4, x, y, 7, 0, dev);
        _new_line(dev);
        return;
    }
    _new_line(dev);
}



void device_registration(struct dev_info* device){
    DEVICES_INFO[DEVICE_COUNT] = *device;
    DEVICE_COUNT++;

    // Если устройство первое, т.е дисплей, то сразу же ищем ему драйвер
    if (DEVICE_COUNT == 1)
        driver_manager();
    device_log(device);
}


//виртуальные устройства
void devices_virt(){

}


void devices_legacy_find(){


    // display vga text mode
    struct dev_info dev_display;
    dev_display.is_pci_dev = 0;
    dev_display.is_virt_dev = 0;
    dev_display.is_leg_dev = 1;

    dev_display.classcode = VIRT_DISPLAY_CONTROLLER;
    dev_display.subclass = VIRT_DISPLAY_VGATEXT;

    device_registration(&dev_display);


    // keyboard
    struct dev_info dev_keyb;
    dev_keyb.is_pci_dev = 0;
    dev_keyb.is_virt_dev = 0;
    dev_keyb.is_leg_dev = 1;

    dev_keyb.classcode = VIRT_KEYBOARD_CONTROLLER;
    dev_keyb.subclass = VIRT_KEYBOARD_LDEV;

    device_registration(&dev_keyb);

}


int devices_find(){

    unsigned int old_device_count = DEVICE_COUNT;

    devices_legacy_find();

    devices_virt();

    pci_find_devices();

    // Возвращает то, сколько нашёл устройств
    return (DEVICE_COUNT-old_device_count);
}
