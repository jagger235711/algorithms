int circle(int x, int n, int k, int a[][N])
{
	for (int i = 0; i < n - 1; i++)
	{
		a[x+i][0+x] = k++;
	}
	//���
	for (int i = 0; i < n - 1; i++)
	{
		a[n + x][i + x] = k++;
	}
	//�³�
	for (int i = n - 1 + x; i > x; i--)
	{
		a[n - 1 + x][i] = k++;
	}
	//�³�
	for (int i = n - 1 + x; i > x; i--)
	{
		a[i][x] = k++;
	}
	//���
	return k;
}