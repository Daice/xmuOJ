#include <stdio.h>
#include <math.h>
int Board[1050][1050],tile=0;
int f(int tr,int tc,int dr,int dc,int size)
{
		int t,s;
			if(size==1)
						return 1;
				tile++;
					t=tile;
						s=size/2;
							if(dr<tr+s && dc<tc+s)
										f(tr,tc,dr,dc,s);
								else
										{
													Board[tr+s-1][tc+s-1]=t;
															f(tr,tc,tr+s-1,tc+s-1,s);
																}

									if(dr<tr+s && dc>=tc+s)
												f(tr,tc+s,dr,dc,s);
										else
												{
															Board[tr+s-1][tc+s]=t;
																	f(tr,tc+s,tr+s-1,tc+s,s);
																		}

											if(dr>=tr+s && dc<tc+s)
														f(tr+s,tc,dr,dc,s);
												else
														{
																	Board[tr+s][tc+s-1]=t;
																			f(tr+s,tc,tr+s,tc+s-1,s);
																				}

													if(dr>=tr+s && dc>=tc+s)
																f(tr+s,tc+s,dr,dc,s);
														else
																{
																			Board[tr+s][tc+s]=t;
																					f(tr+s,tc+s,tr+s,tc+s,s);
																						}
}

int main()
{
		int n,dr,dc,i,j,t;
			scanf("%d",&t);
				n=(int)pow(2,t);
					scanf("%d %d",&dr,&dc);
						f(0,0,dr-1,dc-1,n);
							for(i=0;i<n;i++)
									{
												for(j=0;j<n;j++)
																printf("%d ",Board[i][j]);
														printf("\n");
															}
								return 0;
}
