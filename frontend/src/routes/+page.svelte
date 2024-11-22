<script>
	import VisualSection from "$lib/components/VisualSection.svelte";
	import RawDataTable from "$lib/components/RawDataTable.svelte";

	let readings = [
		{ temperature: 15, humidity: 71, moisture: 461 },
		{ temperature: 19, humidity: 64, moisture: 389 },
		{ temperature: 23, humidity: 38, moisture: 277 }
	];
</script>

<div id="main-container">
	<VisualSection {readings} />
	<RawDataTable {readings} />
</div>

<style>
	#main-container {
		display: grid;
		grid-template-columns: 1fr 1fr;
		grid-template-rows: 1fr;

		height: 100%;
	}
	@media screen and (orientation: portrait) {
		#main-container {
			grid-template-columns: 1fr;
			grid-template-rows: 1fr 1fr;
		}
	}
</style>
