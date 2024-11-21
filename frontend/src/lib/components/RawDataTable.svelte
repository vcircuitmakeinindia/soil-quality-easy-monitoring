<script>
	let data = [
		{
			temperature: 43,
			humidity: 99,
			moisture: 300
		}
	];
</script>

<table id="rawdata-table">
	<caption>Sensor clusters</caption>
	<thead>
		<tr>
			<th>Cluster</th>
			<th>Temperature&#x200a;/&#x200a;&#x2103;</th>
			<th>Humidity&#x200a;/&#x200a;%</th>
			<th>Moisture&#x200a;/&#x200a;a.u.</th>
		</tr>
	</thead>
	<tbody>
		{#each data as cluster, i}
			<tr>
				<td>{i + 1}</td>
				<td>{cluster.temperature}</td>
				<td>{cluster.humidity}</td>
				<td>{cluster.moisture}</td>
			</tr>
		{/each}
	</tbody>
</table>

<style>
	#rawdata-table {
		border-collapse: collapse;

		font-family: "Open Sans", sans-serif;
		font-family: "Parkinsans", sans-serif;
	}

	#rawdata-table th,
	#rawdata-table td {
		padding: 8px;

		border: 1px solid black;

		text-align: center;
	}
</style>
