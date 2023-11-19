#include <stdio.h>
#include <stdint.h>

struct PartitionEntry {
    uint8_t status;
    uint8_t chs_start[3];
    uint8_t type;
    uint8_t chs_end[3];
    uint32_t lba_start;
    uint32_t num_sectors;
};

int main() {
    FILE *mbr_file = fopen("mbr.bin", "rb");
    if (mbr_file == NULL) {
        perror("Erro");
        return 1;
    }

    uint8_t mbr_data[512];
    fread(mbr_data, 1, sizeof(mbr_data), mbr_file);
    fclose(mbr_file);

    struct PartitionEntry *partitions = (struct PartitionEntry *)(mbr_data + 446);

    printf("Dispositivo de Bloco: /dev/sda\n\n");

    for (int i = 0; i < 4; i++) {
        printf("Partition %d:\n", i + 1);
        printf("Status: 0x%02X\n", partitions[i].status);
        printf("Tipo: 0x%02X\n", partitions[i].type);
        printf("Start CHS: %02X:%02X:%02X\n", partitions[i].chs_start[0], partitions[i].chs_start[1], partitions[i].chs_start[2]);
        printf("End CHS: %02X:%02X:%02X\n", partitions[i].chs_end[0], partitions[i].chs_end[1], partitions[i].chs_end[2]);
        printf("LBA Start: %u\n", partitions[i].lba_start);
        printf("Num Sectors: %u\n", partitions[i].num_sectors);
        printf("\n");
    }

    return 0;
}
