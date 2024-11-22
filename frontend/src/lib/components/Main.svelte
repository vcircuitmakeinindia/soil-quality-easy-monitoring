<script>
	import VisualSection from "$lib/components/VisualSection.svelte";
	import RawDataTable from "$lib/components/RawDataTable.svelte";

	const { readings } = $props();
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
