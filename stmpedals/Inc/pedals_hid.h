// C:\Users\aleck\Soft\DT\pedals_1.h


char ReportDescriptor[38] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x01,                    //   USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                    //   USAGE (Joystick)
    0xa1, 0x02,                    //   COLLECTION (Logical)
    0x85, 0x0d,                    //     REPORT_ID (13)
    0x09, 0x01,                    //     USAGE (Pointer)
    0xa1, 0x00,                    //     COLLECTION (Physical)
    0x09, 0x33,                    //       USAGE (Rx)
    0x09, 0x34,                    //       USAGE (Ry)
    0x09, 0x35,                    //       USAGE (Rz)
    0x75, 0x10,                    //       REPORT_SIZE (16)
    0x95, 0x03,                    //       REPORT_COUNT (3)
    0x15, 0x00,                    //       LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x0f,              //       LOGICAL_MAXIMUM (4095)
    0x81, 0x02,                    //       INPUT (Data,Var,Abs)
    0xc0,                          //         END_COLLECTION
    0xc0,                          //     END_COLLECTION
    0xc0                           // END_COLLECTION
};

