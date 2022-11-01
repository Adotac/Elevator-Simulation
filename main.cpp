#include "elevator.h"

int main(void) {
	srand(time(NULL));

	Request riders[MAX_REQUESTS];

	int totalRequests = 0, minutes = 0, users = 0;
	int qFront = 0, qRear = 0;
	int baseFloor = 1;

	int direction = UP; 

	int mFlag = FALSE;
	int input_flr = 0;

	Node* head = NULL;

	for (int i = 0; i < MAX_FLOORS; i++)
	{
		append(&head, i+1);
	}

	//printAllFloors(head);

	//printf("\nFloor: %d", head->floor);

	//head = traverseUpward(head);
	//printf("\nFloor: %d", head->floor);
	//head = traverseDownward(head);
	//printf("\nFloor: %d", head->floor);

	do {
		system("cls");
		
		printf("%s", showQueue(qFront, qRear, riders));

		users = rand() % MAX_USERS;
		printf("\nCurrent active users: %d", users);

		for (int u = 0; u < users; u++) {
			printf("\nInput \'11\' if you want to automate simulation or \'99\' to exit the program.");
			printf("\nWhich floor do you want to go: ");
			scanf_s("%d", &input_flr);

			switch (input_flr) {
			case 99:
				mFlag = TRUE;
				break;
			case 11:
				// AUTO SIMULATION FUNCTION HERE
				mFlag = TRUE;
				break;
			default:
				printf("\nBase floor: %d", baseFloor);
				printf("\nCurrent Floor: %d", head->floor);

				head = inputRequest(totalRequests, qFront, qRear, baseFloor, minutes, input_flr, direction, head);
				break;
			}
			baseFloor = rand() % MAX_FLOORS + 1;
		}
		if (input_flr == 11)
			continue; // skip and terminate loop


	} while (mFlag == FALSE);


	_getch();
}