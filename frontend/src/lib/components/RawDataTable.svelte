<script>
	const { readings } = $props();
</script>

<div id="rawdata-container">
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
			{#each readings as cluster, i}
				<tr>
					<td>{i + 1}</td>
					<td>{cluster.temperature}</td>
					<td>{cluster.humidity}</td>
					<td>{cluster.moisture}</td>
				</tr>
			{/each}
		</tbody>
	</table>
</div>

<style>
	#rawdata-container {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;

		width: 100%;
		height: 100%;

		outline: 1px solid black;
	}

	#rawdata-table {
		border-collapse: collapse;

		font-family: "Parkinsans", sans-serif;
	}

	#rawdata-table th,
	#rawdata-table td {
		padding: 8px;

		border: 1px solid black;

		text-align: center;
	}
</style>
