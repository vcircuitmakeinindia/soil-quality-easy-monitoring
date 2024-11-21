<script>
	import VisualSection from "$lib/components/VisualSection.svelte";
	import RawDataTable from "$lib/components/RawDataTable.svelte";
</script>

<div id="main-container">
	<div id="visual-container">
    <VisualSection />
  </div>
	<div id="rawdata-container">
		<RawDataTable />
	</div>
</div>

<style>
	#main-container {
		display: grid;
		grid-template-columns: 1fr 1fr;
		grid-template-rows: 1fr;

		height: 100%;
	}

	#main-container > * {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;

		width: 100%;
		height: 100%;

		outline: 1px solid black;
	}

	@media screen and (orientation: portrait) {
		#main-container {
			grid-template-columns: 1fr;
			grid-template-rows: 1fr 1fr;
		}
	}

  #visual-container {
    background-image: url("$lib/assets/soil.png");
    background-size: cover;
  }
</style>
