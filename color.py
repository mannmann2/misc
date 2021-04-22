#!/usr/bin/python

cols = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
cols1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

txt = open("color.htm", "w")
txt.write("""<html>

		<head><title>Color Chart</title></head>

	<body> 

		<center><h1>Color Chart</h1></center><br><br>

		<table margin = "1" width="100%">
			<thead>
				<tr><th><h2>Hex</h2></th><th><h2>Color</h2></th><th><h2>Hex</h2></th><th><h2>Color</h2></th><th><h2>Hex</h2></th><th><h2>Color</h2></th><th><h2>Hex</h2></th><th><h2>Color</h2></th></tr>
			</thead>
			<tbody> """)

for c1 in cols1:

	for c2 in cols1:

		if c2 % 2 == 0: 

			for c3 in cols1:

				for c4 in cols1: 

					if c4 % 2 == 0:

						

						for c5 in cols1:

							txt.write('<tr>')

							for c6 in cols1:

								if c6 % 4 == 0:

									txt.write('<td><center>#' + cols[c1] + cols[c2] + cols[c3] + 
												cols[c4] + cols[c5] +  cols[c6] + 
												'<center></td><td style = "background-color: #' +
												cols[c1] + cols[c2] + cols[c3] + 
												cols[c4] + cols[c5] + cols[c6] +
												'"></td>')

						txt.write('</tr>')

txt.write("""</tbody>
			</table>
			</body>
				</html>""")
