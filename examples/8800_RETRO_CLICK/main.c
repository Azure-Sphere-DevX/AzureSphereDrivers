

#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>


#include "as1115.h"
#include "graphics.h"


#include <applibs/log.h>



#include "hw/azure_sphere_learning_path.h"

matrix8x8_t panel8x8 = { .interfaceId = MT3620_ISU1_SPI, .chipSelectId = MT3620_SPI_CS_B, .busSpeed = 10000000, .handle = -1, .bitmap = {0} };


void init_altair_hardware(void) {
	as1115_init(&panel8x8, 1);


	as1115_clear(&panel8x8);

    gfx_load_character('C', panel8x8.bitmap);
    gfx_reverse_panel(panel8x8.bitmap);
    gfx_rotate_counterclockwise(panel8x8.bitmap, 1, 1, panel8x8.bitmap);
    gfx_reverse_panel(panel8x8.bitmap);
    as1115_panel_write(&panel8x8);

}

int main(void)
{
    bool state = true;

    init_altair_hardware();


    while (true) {
        as1115_clear(&panel8x8);
        nanosleep(&(struct timespec) { 1, 0 }, NULL);

        if (state) {
            gfx_load_character('D', panel8x8.bitmap);
        } else {
            gfx_load_character('G', panel8x8.bitmap);
        }

        state = !state;
       
        gfx_reverse_panel(panel8x8.bitmap);
        gfx_rotate_counterclockwise(panel8x8.bitmap, 1, 1, panel8x8.bitmap);
        gfx_reverse_panel(panel8x8.bitmap);
        as1115_panel_write(&panel8x8);



        nanosleep(&(struct timespec) { 1, 0 }, NULL);
    }
}
