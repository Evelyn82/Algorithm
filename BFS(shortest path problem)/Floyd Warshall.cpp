for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) d[i][j] = 0;
				else d[i][j] = INF;
			}
		}

for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (d[i][k] != INF && d[k][j] != INF) {
					if (d[i][j] == 0) {
						d[i][j] = d[i][k] + d[k][j];
					}
					else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
