#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

		int main()
		{

		void sigint_handler(int sig);
		int flag=0;
		int num;
		int buffer;
		int pipefds[2];


			if (signal(SIGINT,sigint_handler)==SIG_ERR)
			{
				perror("signal");
				exit(1);
			}
			if (pipe(pipefds) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		pid_t pid= fork();

		
	if(pid==0)	
	
	{
			printf("Child Process......\n");
			printf("\n Sila masukkan nombor kesukaan anda : \n");
			scanf("%d", &num);
			close(pipefds[0]);
			write(pipefds[1], &num, sizeof(num));
	}
	else if(pid >0)
	{
		wait(NULL);
		close(pipefds[1]);
		read(pipefds[0], &buffer, sizeof(buffer));

			for (int i=2; i<= buffer/2; ++i)
			{



			if(buffer % i == 0)
			{
				flag =1;
				break;
			}
}

			if (buffer == 1)
			{
				printf ("1 is neither prime nor composite...");
			}

			else {
				if (flag==0)
					printf("%d = nombor kesukaan anda ialah nombor perdana....", buffer);
				else
					printf("%d = nombor kesukaan anda ialah bukan nombor perdana....", buffer);

			}
}
	return EXIT_SUCCESS;
			}


		void sigint_handler (int sig)
		{
			printf("TERDAPAT GANGGUAN!! SILA CUBA LAGI, TERIMA KASIH.\t\n");

		}
