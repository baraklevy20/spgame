	//declarations
unsigned char myData1[0x978];
char *myData = (char *)calloc(0x978-0x14, 0x1);
long playerCardCount = 2;
long *playerCardAttribPtr0 = (long *)calloc(96, 4);
long *playerCardAttribPtr1 = (long *)calloc(96, 4);
long *playerCardAttribPtr2 = (long *)calloc(96, 4);
long *playerCardAttribPtr3 = (long *)calloc(96, 4);
//const
const long minPointForLevelDword[29] = {-5L, 1L, 50L, 100L,
									200L, 400L, 800L, 1600L,
									2400L, 3200L, 6400L, 12800L,
									25600L, 51200L, 102400L, 204800L,
									409600L, 819200L, 1638400L, 3276800L,
									6553600L, 13107200L, 26214400L, 52428800L,
									104857600L, 209715200L, 419430400L, 838860800L,
									1677721600L};
const long long minPointForLevelQword[4] = {3355443200LL, 6710886400LL, 13421772800LL, 26843545600LL};
//initial values
long playerCardAttribArr0[2] = {5001, 1311};
long playerCardAttribArr1[2] = {1, 2};
long playerCardAttribArr2[2] = {3, 4};
long playerCardAttribArr3[2] = {5, 6};
memcpy(playerCardAttribPtr0, &playerCardAttribArr0[0], 2*4);
memcpy(playerCardAttribPtr1, &playerCardAttribArr1[0], 2*4);
memcpy(playerCardAttribPtr2, &playerCardAttribArr2[0], 2*4);
memcpy(playerCardAttribPtr3, &playerCardAttribArr3[0], 2*4);


char guildName[13] = "HKGolden";
char guildTitle[13] = "Developer";
long long playerCode = 0;
long long playerPoint = 0;
long playerLevel = 0;
long playerInventorySlots = 12;
long playerType = 1; //set to 7 for GM...
long whiteCards[4] = {0, 0, 0, 0};
long scrolls[3] = {0, 0, 0};
long playerWins = 0;
long playerLoses = 0;
long playerKOs = 0;
long playerDowns = 0;
//
long lobbyMaxRooms = 300;
/* calculate channel flag from playerLevel */
long channelFlag = (playerLevel == 0) ? 0 : (playerLevel >= 17) ? 30 : (playerLevel >= 13) ? 20 : 10;

//build data
memcpy(myData+0x14-0x14, new long(1), 4);
memcpy(myData+0x18-0x14, guildName, strlen(guildName)+1);
memcpy(myData+0x25-0x14, guildTitle, strlen(guildTitle)+1);
memcpy(myData+0x32-0x14, new unsigned char(0), 1); //gender

memcpy(myData+0x34-0x14, &playerWins, 4);
memcpy(myData+0x38-0x14, &playerLoses, 4);
memcpy(myData+0x3C-0x14, new long(0), 4);
memcpy(myData+0x40-0x14, new long(0), 4);
memcpy(myData+0x44-0x14, &playerKOs, 4);
memcpy(myData+0x48-0x14, &playerDowns, 4);

memcpy(myData+0x50-0x14, new long(0), 4);
memcpy(myData+0x54-0x14, new long(0), 4);

memcpy(myData+0x5C-0x14, new long(0), 4);

memcpy(myData+0x60-0x14, &playerPoint, 8); //player point(exp)
memcpy(myData+0x68-0x14, &playerCode, 8); //player code(money)
memcpy(myData+0x70-0x14, new long long(0), 8); //bronze coin

memcpy(myData+0x78-0x14, &playerLevel, 4); //player level (0~32 dec)
memcpy(myData+0x7C-0x14, new long(12), 4); //usable character count

memcpy(myData+0x80-0x14, &scrolls[0], 4); //scroll1
memcpy(myData+0x84-0x14, &scrolls[1], 4); //scroll2
memcpy(myData+0x88-0x14, &scrolls[2], 4); //scroll3
/* white cards */
memcpy(myData+0x8C-0x14, &whiteCards[0], 4); //water
memcpy(myData+0x90-0x14, &whiteCards[1], 4); //fire
memcpy(myData+0x94-0x14, &whiteCards[2], 4); //earth
memcpy(myData+0x98-0x14, &whiteCards[3], 4); //wind

memcpy(myData+0x9C-0x14, &channelFlag, 4); //enterable channel flag
memcpy(myData+0xA0-0x14, &playerCardCount, 4); //param1 of call sub_473430

memcpy(myData+0x280-0x14, playerCardAttribPtr0, 4*96); //param2 of call sub_473430
memcpy(myData+0x400-0x14, playerCardAttribPtr1, 4*96); //param3 of call sub_473430
memcpy(myData+0x580-0x14, playerCardAttribPtr2, 4*96); //param4 of call sub_473430
memcpy(myData+0x700-0x14, playerCardAttribPtr3, 4*96); //param5 of call sub_473430

memcpy(myData+0x880-0x14, &playerInventorySlots, 4);

memcpy(myData+0x884-0x14, &minPointForLevelDword[0], 4*29);
memcpy(myData+0x8F8-0x14, &minPointForLevelQword[0], 4*8);

memcpy(myData+0x94C-0x14, &lobbyMaxRooms, 4);
memcpy(myData+0x974-0x14, &playerType, 4);


CPacket *myPacket = new CPacket(0x4302, myData, 0x978-0x14);
free(myData);
myPacket->Encrypt();
myPacket->Output((char*)myData1, 0x978);
