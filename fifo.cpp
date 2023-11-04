#include<bits/stdc++.h>
using namespace std;

int present(int table_frame[], int nf, int page)
{
	for(int i=0; i<nf; i++)
		if(page == table_frame[i])
			return 1;
	return 0;
}

void printtable(int table_frame[], int nf)
{
	for(int i=0; i<nf; i++)
	{
		if(table_frame[i] == -1)
			cout<<"-- ";
		else
			cout<<" "<<table_frame[i]<<" ";
	}
	cout<<" >> ";
}


int main()
{
    //nf-number of frames
    int n,nf,i,pos=0;

    cout<<"Enter number of frames : ";
    cin>>nf;
    int table_frame[nf];
    for(i=0;i<nf;i++)
    {
        table_frame[i]=-1;
    }

    cout<<"Enter total number of page requests :";
    cin>>n;
    int pages[n];
    cout<<"\nEnter reference string :\n";
    for(i=0;i<n;i++)
    {
        cin>>pages[i];
    }

    int count1=0;
    cout<<"\nPosition of frame table after each request\n\n";
    for(i=0;i<n;i++)
    {
        cout<<"Page table after request from  "<<pages[i]<<" -> ";
        if(!present(table_frame,nf,pages[i]))
        {
           table_frame[pos] = pages[i];
           pos = (pos+1)%nf ;//considering it as a queue
           printtable(table_frame,nf);
           cout<<"Page Fault\n";
           count1++;
           continue;
        }

        printtable(table_frame,nf);
		cout<<"\n";

    }
    cout<<"\nNumber of page faults : "<<count1;
    cout<<"\nNumber of page Hit : "<<n-count1<<endl<<endl;
}
