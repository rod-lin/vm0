# vm

add_lib_batch(vm0-vm SHARED "*.c")

target_link_libraries(vm0-vm m vm0-std)
